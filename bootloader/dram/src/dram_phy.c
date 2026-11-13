// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * The DesignWare LPDDR5 PHY: table-driven register setup, the save list in
 * the PHY's sequence memory, and firmware load.
 */

#include "dram_internal.h"

#define SAVE_EVEN	0x08
#define SAVE_ODD	0x10

/*
 * The save list: for each Pstate the PHY keeps a list of register values to
 * restore when it switches to that Pstate. A record is four words: the
 * values of an even register and of the odd one after it, the register
 * address divided by two, and above its 16 bits which of the two are valid.
 */
void phy_save_record(struct dram *d, uint32_t addr, uint16_t even,
		     uint16_t odd, unsigned int valid)
{
	phy_wr(d, d->save.ptr++, even);
	phy_wr(d, d->save.ptr++, odd);
	phy_wr(d, d->save.ptr++, (uint16_t)(addr >> 1));
	phy_wr(d, d->save.ptr++, (uint16_t)((addr >> 17) | valid));
}

void phy_save_flush(struct dram *d)
{
	if (d->save.valid)
		phy_save_record(d, d->save.addr, d->save.val[0],
				d->save.val[1], d->save.valid);
	d->save.valid = 0;
}

void phy_save_seek(struct dram *d, uint32_t ptr)
{
	phy_save_flush(d);
	d->save.ptr = ptr;
}

/*
 * Write a register and put it on the save list. A record is held back until
 * the next saved write, so that the two halves of a pair share one record.
 */
void phy_wr_saved(struct dram *d, uint32_t reg, uint16_t val)
{
	unsigned int half = reg & 1;
	uint8_t bit = half ? SAVE_ODD : SAVE_EVEN;
	uint8_t other = half ? SAVE_EVEN : SAVE_ODD;

	phy_wr(d, reg, val);

	if (d->save.valid == other && d->save.addr == (reg & ~1u)) {
		d->save.val[half] = val;
		d->save.valid |= bit;
		phy_save_flush(d);
		return;
	}

	phy_save_flush(d);
	d->save.addr = reg & ~1u;
	d->save.val[half] = val;
	d->save.val[!half] = 0;
	d->save.valid = bit;
}

static void phy_run_ops(struct dram *d, const struct phy_op *ops,
			unsigned int count, unsigned int pstate,
			uint32_t lane_off, uint32_t ac_off)
{
	const struct dram_freq_cfg *f = d->freq[pstate];
	unsigned int i;

	for (i = 0; i < count; i++) {
		uint32_t reg = ops[i].addr;
		uint16_t val = ops[i].val;

		/* Only registers of a byte lane or an AC group move. */
		if ((reg >> 16) == 0x1)
			reg += lane_off;
		else if ((reg >> 16) == 0x3)
			reg += ac_off;

		if (ops[i].flags & PHY_VAR)
			val = f->phy[val];
		else if (ops[i].flags & PHY_QFREQ)
			val = d->mhz[pstate] / 4;
		else if (ops[i].flags & PHY_NZ)
			val |= pstate ? 1 : 0;

		if (ops[i].flags & PHY_SAVE)
			phy_wr_saved(d, reg, val);
		else
			phy_wr(d, reg, val);
	}
}

static void phy_run_loop(struct dram *d, const struct phy_op *ops,
			 unsigned int count, unsigned int loop,
			 unsigned int pstate)
{
	unsigned int lane, bit, ac;

	switch (loop) {
	case PHY_LOOP_LANE:
		for (lane = 0; lane < BYTE_LANES; lane++)
			phy_run_ops(d, ops, count, pstate,
				    lane * LANE_STRIDE, 0);
		break;
	case PHY_LOOP_LANE_BIT:
		for (lane = 0; lane < BYTE_LANES; lane++)
			for (bit = 0; bit < LANE_BITS; bit++)
				phy_run_ops(d, ops, count, pstate,
					    lane * LANE_STRIDE +
					    bit * BIT_STRIDE, 0);
		break;
	case PHY_LOOP_AC:
		for (ac = 0; ac < AC_GROUPS; ac++)
			phy_run_ops(d, ops, count, pstate, 0,
				    ac * LANE_STRIDE);
		break;
	default:
		phy_run_ops(d, ops, count, pstate, 0, 0);
		break;
	}
}

void phy_run_groups(struct dram *d, const struct phy_group *groups,
		    unsigned int count, unsigned int pstate)
{
	unsigned int i;

	for (i = 0; i < count; i++)
		phy_run_loop(d, groups[i].ops, groups[i].count,
			     groups[i].loop, pstate);
}

void phy_run_steps(struct dram *d, const struct phy_step *steps,
		   unsigned int count, unsigned int pstate)
{
	unsigned int i, n;

	for (i = 0; i < count; i++) {
		const struct phy_step *s = &steps[i];

		switch (s->type) {
		case PHY_STEP_DATA:
			for (n = 0; n < s->count; n++)
				phy_wr(d, s->addr + n, s->data[n]);
			break;
		case PHY_STEP_FILL:
			phy_fill(d, s->addr, s->count, s->val);
			break;
		case PHY_STEP_PAYLOAD:
			phy_load(d, s->addr, s->count, s->offset);
			break;
		default:
			phy_run_loop(d, s->ops, s->count, s->type, pstate);
			break;
		}
	}
}

/* Settings that do not depend on the Pstate. */
void phy_init_common(struct dram *d)
{
	phy_run_groups(d, phy_common, phy_common_count, 0);
}

/* The firmware code goes to the instruction memory once. */
void phy_load_firmware(struct dram *d)
{
	phy_load(d, PHY_IMEM, PAYLOAD_LP5_IMEM_WORDS, PAYLOAD_LP5_IMEM);
	phy_fill(d, PHY_IMEM + PAYLOAD_LP5_IMEM_WORDS,
		 PHY_DMEM - PHY_IMEM - PAYLOAD_LP5_IMEM_WORDS, 0);
}

/*
 * Static configuration for the frequency of a Pstate. Nearly all of it also
 * goes to the save list of that Pstate: the clock settings to its head, the
 * rest to the main part.
 */
void phy_config_pstate(struct dram *d, unsigned int pstate)
{
	uint32_t area = PHY_SAVE_AREA(pstate);

	phy_save_seek(d, area + PHY_SAVE_HEAD);
	phy_run_groups(d, phy_cfg_head, phy_cfg_head_count, pstate);

	phy_save_seek(d, area + PHY_SAVE_MAIN);
	phy_run_groups(d, phy_cfg_main, phy_cfg_main_count, pstate);
	phy_save_flush(d);

	d->save_main[pstate] = d->save.ptr;
}

/*
 * After the last Pstate: load the sequences the PHY runs by itself, the long
 * ones from the payload. The two values that depend on the frequency follow
 * Pstate 0.
 */
void phy_finish(struct dram *d)
{
	phy_wr(d, PHY_MUX, 0);
	dram_udelay(d, 1);
	phy_run_steps(d, phy_final_steps, phy_final_step_count, 0);
}
