// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Supply rails, the DDR PLL, the DRAM clock and the resets and gates in the
 * CCU and in the glue block.
 */

#include "dram_internal.h"

#define PLL_ENABLE		(1u << 31)
#define PLL_LDO_ENABLE		(1u << 30)
#define PLL_LOCK_ENABLE		(1u << 29)
#define PLL_LOCKED		(1u << 28)
#define PLL_OUTPUT_ENABLE	(1u << 27)
#define PLL_FACTOR_FIELDS	0x0170ff02u
#define PLL_FACTOR_FIXED	0x01000000u

#define DRAM_CLK_GATE		(1u << 31)
#define DRAM_CLK_UPDATE		(1u << 27)
#define DRAM_CLK_SRC_MASK	(7u << 24)
#define DRAM_CLK_DIV_MASK	0x1fu

#define BGR_GATE		(1u << 0)
#define BGR_RESET		(1u << 16)

/*
 * Rails for LPDDR5 with the first rail set: the second voltage on dcdc7 and
 * eldo1, then the first voltage on dcdc6.
 */
int dram_power(struct dram *d)
{
	const uint32_t *w = d->para->word;
	unsigned int v1 = ((w[25] >> 8) & 0xff) * 10;
	unsigned int v2 = ((w[22] >> 20) & 0xff) * 10;
	const struct a733_dram_ops *ops = d->ops;

	if (w[25] & (1u << 20)) {
		dram_fail(d, "DRAM: second rail set is not supported", w[25]);
		return -1;
	}

	if (!v2)
		v2 = 1080;
	if (w[22] & (1u << 16))
		v2 = 1200;

	if (ops->pmic_set(ops->ctx, A733_DRAM_RAIL_DCDC7, v2) ||
	    ops->pmic_set(ops->ctx, A733_DRAM_RAIL_ELDO1, v2) ||
	    ops->pmic_set(ops->ctx, A733_DRAM_RAIL_DCDC6, v1)) {
		dram_fail(d, "DRAM: PMIC rail could not be set", 0);
		return -1;
	}

	dram_log(d, "DRAM_VCC set to (mV)", v1);
	return 0;
}

static void dram_clock_set_divider(struct dram *d, unsigned int div)
{
	rmw32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_DIV_MASK & ~div,
	      DRAM_CLK_UPDATE | div);
}

/* Hold everything, start the PLL at clock MHz, then release in order. */
void dram_clocks_init(struct dram *d)
{
	uint32_t n = d->para->word[A733_DRAM_CLK] / 24;
	uint32_t factors = PLL_FACTOR_FIXED | ((n - 1) << 8);

	rmw32(d, CCU_BASE + CCU_DRAM_GATE2, 1u << 31, 1u << 27);
	clrbits32(d, CCU_BASE + CCU_DRAM_GATE1, 1u << 0);
	clrbits32(d, CCU_BASE + CCU_DRAM_GATE1, 1u << 16);
	clrbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_RESET);
	clrbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_GATE);
	setbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_RESET);
	setbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_GATE);
	rmw32(d, GLUE_BASE + GLUE_CTRL, 0x2600, 0x0100);
	rmw32(d, GLUE_BASE + GLUE_CTRL, 0x0100, 0x2600);
	clrbits32(d, CCU_BASE + CCU_PLL_DDR, PLL_ENABLE);
	rmw32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_GATE, DRAM_CLK_UPDATE);
	dram_udelay(d, 5);

	/* 24 MHz * N */
	rmw32(d, CCU_BASE + CCU_PLL_DDR, PLL_FACTOR_FIELDS & ~factors,
	      factors);
	setbits32(d, CCU_BASE + CCU_PLL_DDR, PLL_ENABLE | PLL_LDO_ENABLE);
	setbits32(d, CCU_BASE + CCU_PLL_DDR,
		  PLL_ENABLE | PLL_LDO_ENABLE | PLL_LOCK_ENABLE);
	dram_udelay(d, 20);
	wait32(d, CCU_BASE + CCU_PLL_DDR, PLL_LOCKED, PLL_LOCKED);
	setbits32(d, CCU_BASE + CCU_PLL_DDR, PLL_ENABLE | PLL_LDO_ENABLE |
		  PLL_LOCK_ENABLE | PLL_OUTPUT_ENABLE);

	/* DRAM clock from the PLL, at the divider of Pstate 0 */
	dram_clock_set_divider(d, d->divider[0]);
	rmw32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_SRC_MASK, DRAM_CLK_UPDATE);
	setbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_RESET);
	setbits32(d, CCU_BASE + CCU_DRAM_BGR, BGR_GATE);
	rmw32(d, CCU_BASE + CCU_DRAM_GATE2, 0x06000000, 0x89000000);
	setbits32(d, CCU_BASE + CCU_DRAM_GATE1, 1u << 16);
	setbits32(d, CCU_BASE + CCU_DRAM_GATE1, 1u << 0);
	rmw32(d, CCU_BASE + CCU_DRAM_GATE0, 0x04000000, 0xcb000000);
	setbits32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_GATE | DRAM_CLK_UPDATE);
	dram_udelay(d, 5);

	/* Glue: two channels, LPDDR5 */
	clrbits32(d, GLUE_BASE + GLUE_CTRL, 0x0014);
	clrbits32(d, GLUE_BASE + GLUE_CTRL, 0x0028);
	rmw32(d, GLUE_BASE + GLUE_CTRL, 0x1817, 0x2728);
	setbits32(d, GLUE_BASE + 0x14, 0x3);
	wr32(d, GLUE_BASE + 0x21c, 0x0103);
	wr32(d, GLUE_BASE + 0x220, 0x13ff);
	wr32(d, GLUE_BASE + 0x224, 0x0103);
	wr32(d, GLUE_BASE + 0x228, 0x13ff);
	wr32(d, GLUE_BASE + 0x21c, 0x0107);
	wr32(d, GLUE_BASE + 0x224, 0x0107);

	setbits32(d, PRCM_BASE + PRCM_PAD_HOLD, 1);
	dram_udelay(d, 10000);
}

/* Controller and PHY out of reset, in two steps. */
void dram_glue_release_resets(struct dram *d)
{
	setbits32(d, GLUE_BASE + GLUE_CTRL, 0x14);
	rmw32(d, GLUE_BASE + GLUE_CTRL, 0x1, 0x2);
	dram_udelay(d, 1);
	setbits32(d, GLUE_BASE + GLUE_CTRL, 0x3);
	dram_udelay(d, 1);
}

/* Switch the DRAM clock to the divider of a Pstate. */
void dram_clock_set_pstate(struct dram *d, unsigned int pstate)
{
	unsigned int div = d->divider[pstate];

	clrbits32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_SRC_MASK);
	rmw32(d, CCU_BASE + CCU_DRAM_CLK, DRAM_CLK_DIV_MASK & ~div, div);
	dram_clock_set_divider(d, div);
	dram_udelay(d, 1000);
}
