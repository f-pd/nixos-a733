// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * The two DesignWare DDR controllers: static setup, address map, timing per
 * Pstate, mode register access, handover from the PHY and the adjustments
 * after training.
 *
 * Register names follow the DesignWare layout where the specification
 * identifies them; the others are named after what the driver does there.
 */

#include "dram_internal.h"

#define DFIMISC_INIT_COMPLETE_EN	(1u << 0)
#define DFIMISC_INIT_START		(1u << 5)
#define DFIMISC_PSTATE_MASK		(0x1fu << 8)
#define DFIMISC_PSTATE(p)		((uint32_t)(p) << 8)

#define PWRCTL_SELFREF_SW		(1u << 11)

#define MRCTRL0_READ			(1u << 0)
#define MRCTRL0_RANK(r)			(1u << ((r) + 4))
#define MRCTRL0_START			(1u << 31)

void ctl_sw_open(struct dram *d, unsigned int ch)
{
	wr32(d, CTL_BASE(ch) + CTL_SWCTL, 0);
}

void ctl_sw_close(struct dram *d, unsigned int ch)
{
	wr32(d, CTL_BASE(ch) + CTL_SWCTL, 1);
}

void ctl_sw_close_wait(struct dram *d, unsigned int ch)
{
	ctl_sw_close(d, ch);
	wait32(d, CTL_BASE(ch) + CTL_SWSTAT, 1, 1);
}

static void ctl_init_static(struct dram *d, uint32_t base)
{
	/* LPDDR5, two ranks */
	wr32(d, base + CTL_MSTR, 0x03081008);
	wr32(d, base + 0x10c9c, 0x00000303);
	rmw32(d, base + 0x10010, 0x00000100, 0x00000001);
	clrbits32(d, base + 0x1018c, 0x0000003f);
	rmw32(d, base + CTL_PWRCTL, 0x000000ff, PWRCTL_SELFREF_SW);
	rmw32(d, base + 0x10508, 0x00008000, 0xc0000000);
	rmw32(d, base + 0x10280, 0x20000000, 0x80000000);
	setbits32(d, base + 0x10288, 0x00000001);
	rmw32(d, base + 0x10300, 0x003f003f, 0x00c000c0);
	setbits32(d, base + 0x10308, 0x00000001);
	wr32(d, base + 0x10500, 0);
	rmw32(d, base + 0x10518, 0xda000001, 0x25000000);
	setbits32(d, base + 0x10208, 0x00000001);
	rmw32(d, base + CTL_DFIMISC, 0x00020000, 0x00010015);
}

/*
 * The part of the address map that depends on the memory fit, chosen by the
 * row field of para1 and the three-quarter flag.
 */
struct ctl_addrmap {
	uint8_t rows;
	uint8_t three_quarter;
	uint8_t has_map12;
	uint32_t map7;		/* upper row bits */
	uint32_t map12;
	uint32_t map1;		/* rank select */
};

static const struct ctl_addrmap ctl_addrmaps[] = {
	{ 15, 0, 0, 0x1f1f1f08, 0, 0x3f17 },	/*  4 GiB */
	{ 16, 1, 1, 0x1f1f0909, 3, 0x3f16 },	/*  6 GiB */
	{ 16, 0, 0, 0x1f1f0808, 0, 0x3f18 },	/*  8 GiB */
	{ 17, 1, 0, 0x1f090908, 0, 0x3f17 },	/* 12 GiB */
};

static void ctl_init_addrmap(struct dram *d, uint32_t base)
{
	uint32_t para1 = d->para->word[A733_DRAM_PARA1];
	unsigned int rows = (para1 >> 4) & 0xff;
	unsigned int tq = !!(d->para->word[A733_DRAM_TPR13] &
			     TPR13_THREE_QUARTER);
	const struct ctl_addrmap *map = NULL;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(ctl_addrmaps); i++)
		if (ctl_addrmaps[i].rows == rows &&
		    ctl_addrmaps[i].three_quarter == tq)
			map = &ctl_addrmaps[i];

	if (!map) {
		dram_fail(d, "DRAM: no address map for geometry", para1);
		return;
	}

	wr32(d, base + 0x30018, 0x02020200);
	wr32(d, base + 0x30014, 0x1f020202);
	wr32(d, base + 0x30010, 0x00000101);
	wr32(d, base + 0x3000c, 0x003f0909);
	wr32(d, base + 0x3002c, 0x00000808);
	wr32(d, base + 0x30028, 0x08080808);
	wr32(d, base + 0x30024, 0x08080808);
	wr32(d, base + 0x30020, 0x08080808);
	wr32(d, base + 0x3001c, map->map7);
	if (map->has_map12)
		wr32(d, base + 0x30030, map->map12);
	wr32(d, base + 0x30004, map->map1);
	wr32(d, base + 0x10220, 0x0a090e01);
	wr32(d, base + 0x10224, 0);
}

/* Timing registers of one Pstate, from the row of its frequency. */
static void ctl_init_timing(struct dram *d, uint32_t base, unsigned int pstate)
{
	const struct dram_freq_cfg *f = d->freq[pstate];
	uint32_t set = base + CTL_PSTATE(pstate);
	unsigned int i;

	for (i = 0; i < ctl_timing_op_count; i++) {
		const struct ctl_timing_op *op = &ctl_timing_ops[i];
		uint32_t val = op->var == FC_NONE ? op->val : f->ctl[op->var];

		if (op->mask)
			rmw32(d, set + op->off, op->mask & ~val, val);
		else
			wr32(d, set + op->off, val);

		/* The refresh setup is global and follows Pstate 0. */
		if (op->off == 0xd00 && pstate == 0) {
			rmw32(d, base + CTL_RFSH, 0xc3ff1fff & ~f->ctl_rfsh,
			      f->ctl_rfsh);
			clrbits32(d, base + CTL_DFIMISC,
				  DFIMISC_INIT_COMPLETE_EN);
		}
	}

	udelay(d, 20);
}

void ctl_init(struct dram *d, unsigned int ch)
{
	uint32_t base = CTL_BASE(ch);
	unsigned int p;

	wr32(d, base + 0x10380, 0x80013414);
	for (p = 0; p < PSTATES; p++)
		wr32(d, base + CTL_PSTATE(p) + 0xc00, 0xff);
	setbits32(d, base + CTL_RETRAIN, 1);
	wr32(d, base + 0x10184, 2);

	ctl_init_static(d, base);
	ctl_init_addrmap(d, base);

	for (p = PSTATES; p-- > 0;)
		ctl_init_timing(d, base, p);

	clrbits32(d, base + CTL_RETRAIN, 1);

	ctl_sw_open(d, ch);
	rmw32(d, base + CTL_DFIMISC, 0x00020011, 0x00010004);
	ctl_sw_close_wait(d, ch);

	ctl_sw_open(d, ch);
	rmw32(d, base + CTL_DFIMISC, 0x00020001, 0x00010014);
	ctl_sw_close_wait(d, ch);
}

/* Tell both controllers which Pstate the PHY is about to be trained for. */
void ctl_select_pstate(struct dram *d, unsigned int pstate)
{
	unsigned int ch;

	for (ch = 0; ch < CHANNELS; ch++) {
		ctl_sw_open(d, ch);
		rmw32(d, CTL_BASE(ch) + CTL_DFIMISC,
		      DFIMISC_PSTATE_MASK & ~DFIMISC_PSTATE(pstate),
		      DFIMISC_PSTATE(pstate));
		ctl_sw_close(d, ch);
	}
}

static void ctl_mr_access(struct dram *d, uint32_t base, uint32_t ctrl,
			  uint32_t data)
{
	wait32(d, base + CTL_MRSTAT, 1, 0);
	wr32(d, base + CTL_MRCTRL0, ctrl);
	wr32(d, base + CTL_MRCTRL1, data);
	wr32(d, base + CTL_MRCTRL0, ctrl | MRCTRL0_START);
	wait32(d, base + CTL_MRCTRL0, MRCTRL0_START, 0);
}

/* Write a mode register on both ranks of a channel. */
void ctl_mr_write(struct dram *d, unsigned int ch, unsigned int reg,
		  unsigned int val)
{
	unsigned int rank;

	for (rank = 0; rank < RANKS; rank++)
		ctl_mr_access(d, CTL_BASE(ch), MRCTRL0_RANK(rank),
			      (reg << 8) | val);
}

unsigned int ctl_mr_read(struct dram *d, unsigned int ch, unsigned int rank,
			 unsigned int reg)
{
	ctl_mr_access(d, CTL_BASE(ch), MRCTRL0_RANK(rank) | MRCTRL0_READ,
		      reg << 8);

	return (rd32(d, GLUE_BASE + GLUE_MRR(ch)) >> 8) & 0xff;
}

static unsigned int max2(unsigned int a, unsigned int b)
{
	return a > b ? a : b;
}

static unsigned int max4(unsigned int a, unsigned int b, unsigned int c,
			 unsigned int e)
{
	return max2(max2(a, b), max2(c, e));
}

/* Add to a register field, saturating at the field's maximum. */
static uint32_t field_add(uint32_t reg, unsigned int shift, unsigned int width,
			  unsigned int add)
{
	uint32_t max = (1u << width) - 1;
	uint32_t val = ((reg >> shift) & max) + add;

	if (val > max)
		val = max;

	return (reg & ~(max << shift)) | (val << shift);
}

/* Training results in the PHY data memory, words 0x13-0x18 and 0x20-0x26 */
#define RESULT_LO(r, n)	((unsigned int)((r)[(n) - 0x13] & 0xff))
#define RESULT_HI(r, n)	((unsigned int)((r)[(n) - 0x13] >> 8))

/*
 * Add the delay differences the PHY reports, between ranks and between read
 * and write, to the turnaround timings of Pstate 0.
 */
void ctl_adjust_timing(struct dram *d, unsigned int ch)
{
	uint32_t base = CTL_BASE(ch);
	uint16_t r[0x27 - 0x13];
	unsigned int a, b, c, dd, e, f, g, h, i, n;
	unsigned int ratio, dly;
	uint32_t v;

	phy_wr(d, PHY_MUX, 0);
	phy_wr(d, PHY_SEQ_PSTATE, 3);
	for (n = 0x13; n <= 0x26; n++)
		r[n - 0x13] = (n <= 0x18 || n >= 0x20) ?
			      phy_rd(d, PHY_DMEM + n) : 0;
	phy_wr(d, PHY_SEQ_PSTATE, 0);
	phy_wr(d, PHY_MUX, 1);

	a = max4(RESULT_HI(r, 0x18), RESULT_LO(r, 0x18),
		 RESULT_LO(r, 0x26), RESULT_HI(r, 0x25));
	b = max2(RESULT_HI(r, 0x13), RESULT_LO(r, 0x13));
	c = max2(RESULT_LO(r, 0x21), RESULT_HI(r, 0x20));
	dd = max4(RESULT_HI(r, 0x14), RESULT_LO(r, 0x15),
		  RESULT_HI(r, 0x22), RESULT_LO(r, 0x22));
	e = max4(RESULT_HI(r, 0x16), RESULT_LO(r, 0x17),
		 RESULT_HI(r, 0x24), RESULT_LO(r, 0x24));
	f = max2(RESULT_HI(r, 0x15), RESULT_LO(r, 0x14));
	g = max2(RESULT_HI(r, 0x21), RESULT_LO(r, 0x23));
	h = max2(RESULT_HI(r, 0x17), RESULT_LO(r, 0x16));
	i = max2(RESULT_LO(r, 0x25), RESULT_HI(r, 0x23));

	setbits32(d, base + CTL_RETRAIN, 1);
	wait32(d, base + CTL_RETRAIN_ST, 3u << 25, 3u << 25);
	wait32(d, base + CTL_RETRAIN_ST, 3u << 28, 3u << 28);

	ctl_sw_open(d, ch);
	wait32(d, base + CTL_SWSTAT, 1, 0);

	v = rd32(d, base + 0xd04);
	v = field_add(v, 8, 8, a);
	v = field_add(v, 0, 8, max2(b, c));
	wr32(d, base + 0xd04, v);

	v = rd32(d, base + 0xd08);
	v = field_add(v, 8, 8, dd);
	v = field_add(v, 0, 8, e);
	wr32(d, base + 0xd08, v);

	v = rd32(d, base + 0x008);
	v = field_add(v, 8, 8, max2(f, g));
	v = field_add(v, 0, 8, max2(h, i));
	wr32(d, base + 0x008, v);

	wr32(d, base + 0x060, field_add(rd32(d, base + 0x060), 16, 8, dd));
	wr32(d, base + 0x024, field_add(rd32(d, base + 0x024), 0, 8, e));
	wr32(d, base + 0x584, field_add(rd32(d, base + 0x584), 16, 5, a));

	phy_wr(d, PHY_MUX, 0);
	ratio = phy_rd(d, 0x20002) & 0xf;
	dly = phy_rd(d, 0x1002a) & 0x1f;
	phy_wr(d, PHY_MUX, 1);

	v = (dly >> 1) + (((ratio + 1) >> 3) << 2) + 0x15;
	rmw32(d, base + 0x588, 0x3fu << 16, (v & 0x3f) << 16);

	ctl_sw_close_wait(d, ch);
	clrbits32(d, base + CTL_RETRAIN, 1);
}

/* Start the DFI initialisation and bring both controllers to normal mode. */
void ctl_handover(struct dram *d)
{
	unsigned int ch;

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_open(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		setbits32(d, CTL_BASE(ch) + CTL_DFIMISC,
			  0x1000 | DFIMISC_INIT_COMPLETE_EN);
	for (ch = 0; ch < CHANNELS; ch++)
		setbits32(d, CTL_BASE(ch) + CTL_DFIMISC, DFIMISC_INIT_START);
	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_close(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		wait32(d, CTL_BASE(ch) + CTL_SWSTAT, 1, 1);
	for (ch = 0; ch < CHANNELS; ch++)
		wait32(d, CTL_BASE(ch) + CTL_DFISTAT, 1, 1);
	udelay(d, 50);

	setbits32(d, PRCM_BASE + PRCM_PAD_HOLD, 1);
	udelay(d, 2000);

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_open(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		clrbits32(d, CTL_BASE(ch) + CTL_DFIMISC, DFIMISC_INIT_START);
	for (ch = 0; ch < CHANNELS; ch++)
		clrbits32(d, CTL_BASE(ch) + CTL_PWRCTL, PWRCTL_SELFREF_SW);
	for (ch = 0; ch < CHANNELS; ch++) {
		wait32(d, CTL_BASE(ch) + CTL_STAT, 3u << 4, 0);
		wait32(d, CTL_BASE(ch) + CTL_STAT, 3u << 0, 1);
	}
	udelay(d, 50);

	for (ch = 0; ch < CHANNELS; ch++)
		clrbits32(d, CTL_BASE(ch) + CTL_DFIMISC,
			  DFIMISC_INIT_COMPLETE_EN);
	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_close(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		wait32(d, CTL_BASE(ch) + CTL_SWSTAT, 1, 1);
	udelay(d, 2);
}

struct reg_write {
	uint32_t addr;
	uint32_t val;
};

/* Written once both controllers run; the registers are not named. */
static const struct reg_write remap_writes[] = {
	{ SYS2_BASE + 0x4818, 0x00008002 },
	{ SYS2_BASE + 0x481c, 0xffffffff },
	{ GLUE_BASE + 0x10018, 0x00008002 },
	{ GLUE_BASE + 0x20018, 0x00008002 },
	{ GLUE_BASE + 0x10068, 0xffffffff },
	{ GLUE_BASE + 0x20068, 0xffffffff },
	{ SYS2_BASE + 0x4838, 0x00000002 },
	{ SYS2_BASE + 0x448c, 0x00000002 },
	{ SYS2_BASE + 0x468c, 0x00000002 },
	{ SYS2_BASE + 0x3a04, 0xffffffff },
	{ SYS2_BASE + 0x3c04, 0xffffffff },
	{ SYS2_BASE + 0x3e04, 0xffffffff },
	{ SYS2_BASE + 0x4004, 0xffffffff },
	{ SYS2_BASE + 0x4204, 0xffffffff },
	{ SYS2_BASE + 0x4490, 0x10102010 },
	{ SYS2_BASE + 0x4494, 0x08081008 },
	{ SYS2_BASE + 0x4690, 0x10102010 },
	{ SYS2_BASE + 0x4694, 0x08081008 },
};

void ctl_remap(struct dram *d)
{
	unsigned int ch, i;

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_open(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		wr32(d, CTL_BASE(ch) + 0x10208, 0);
	for (ch = 0; ch < CHANNELS; ch++)
		rmw32(d, CTL_BASE(ch) + CTL_DFIMISC, 0x8000, 0x4000);
	for (ch = 0; ch < CHANNELS; ch++)
		ctl_sw_close(d, ch);
	for (ch = 0; ch < CHANNELS; ch++)
		wait32(d, CTL_BASE(ch) + CTL_SWSTAT, 1, 1);

	for (i = 0; i < ARRAY_SIZE(remap_writes); i++)
		wr32(d, remap_writes[i].addr, remap_writes[i].val);
}

static void dfs_write_segment(struct dram *d, const struct dfs_segment *seg)
{
	unsigned int i;

	for (i = 0; i < seg->count; i++)
		wr32(d, GLUE_BASE + seg->words[i].off, seg->words[i].val);
}

/* Per-Pstate word of the frequency-change parameters: the clock divider. */
static uint32_t dfs_clock_word(struct dram *d, unsigned int pstate)
{
	return ((uint32_t)d->divider[pstate] << 19) |
	       ((8 * pstate + 5) << 8) | (8 * pstate + 1);
}

/*
 * Fill the script the hardware runs for frequency changes at run time: four
 * groups of one parameter word per Pstate, each followed by a part of the
 * script, after a first part of the script without parameters.
 */
void ctl_dfs_setup(struct dram *d)
{
	unsigned int group, p;
	uint32_t val;

	dfs_write_segment(d, &dfs_segments[0]);

	for (group = 0; group < DFS_SEGMENTS - 1; group++) {
		for (p = 0; p < PSTATES; p++) {
			switch (group) {
			case 0:
				val = 0x1001;
				break;
			case 1:
				val = 0x4000;
				break;
			case 2:
				val = p;
				break;
			default:
				val = dfs_clock_word(d, p);
				break;
			}
			wr32(d, GLUE_BASE + GLUE_DFS_PARAM + 16 * group + 4 * p,
			     val);
		}
		dfs_write_segment(d, &dfs_segments[group + 1]);
	}
}
