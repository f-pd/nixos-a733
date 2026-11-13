// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * DRAM parameter blocks of the Orange Pi Zero 3W and what is derived from
 * them directly.
 */

#include "dram_internal.h"

/*
 * The four blocks are listed in docs/dram-init-spec.md, "The four parameter
 * blocks". This is the default one, for 4 GiB.
 */
static const uint32_t para_default[32] = {
	[0] = 2400,
	[1] = PARA_TYPE_LPDDR5,
	[2] = 0x0e0e0e0e,
	[3] = 0x0f0f0f0f,
	[4] = 0xec030e0f,
	[6] = 0xa0fa,
	[7] = 0x1001,
	[11] = 6,
	[15] = 0x14,
	[16] = 0x44,
	[18] = 0x28,
	[20] = 6,
	[22] = 0x4040,
	[24] = 0x170b0703,
	[25] = 0x3800,
	[26] = 0x3514,
	[27] = 0x325f0000,
	[30] = 0x65,
};

/* The words in which an alternative block differs from the default. */
struct para_delta {
	uint8_t word;
	uint32_t val;
};

struct para_alt {
	uint8_t strap;
	uint8_t count;
	const struct para_delta *delta;
};

static const struct para_delta para_6g[] = {
	{ 6, 0xa10a }, { 15, 0x13 }, { 18, 0x2e }, { 30, 0x10065 },
};

static const struct para_delta para_8g[] = {
	{ 0, 2040 }, { 6, 0xa10a }, { 15, 0x13 }, { 18, 0x2e },
	{ 20, 0x86 }, { 22, 0x07004040 }, { 24, 0x13090603 },
	{ 27, 0xb25f0000 }, { 30, 0x65 },
};

static const struct para_delta para_12g[] = {
	{ 0, 2040 }, { 6, 0xa11a }, { 15, 0x13 }, { 18, 0x2e },
	{ 20, 0x86 }, { 22, 0x07004040 }, { 24, 0x13090603 },
	{ 27, 0xb25f0000 }, { 30, 0x10065 },
};

static const struct para_alt para_alts[] = {
	{ 1, ARRAY_SIZE(para_6g), para_6g },
	{ 2, ARRAY_SIZE(para_8g), para_8g },
	{ 5, ARRAY_SIZE(para_12g), para_12g },
};

void a733_dram_select_para(unsigned int strap, struct a733_dram_para *para)
{
	unsigned int i, j;

	for (i = 0; i < A733_DRAM_PARA_WORDS; i++)
		para->word[i] = i < ARRAY_SIZE(para_default) ?
				para_default[i] : 0;

	for (i = 0; i < ARRAY_SIZE(para_alts); i++) {
		if (para_alts[i].strap != strap)
			continue;
		for (j = 0; j < para_alts[i].count; j++)
			para->word[para_alts[i].delta[j].word] =
				para_alts[i].delta[j].val;
	}
}

static const struct dram_freq_cfg *freq_lookup(unsigned int mhz)
{
	unsigned int i;

	for (i = 0; i < dram_freq_table_count; i++)
		if (dram_freq_table[i].mhz == mhz)
			return &dram_freq_table[i];

	return NULL;
}

/*
 * Reject what this driver does not implement, and work out the Pstate
 * frequencies: clock * 4 / (divider + 1), one divider byte per Pstate.
 */
int dram_para_check(struct dram *d)
{
	const uint32_t *w = d->para->word;
	uint32_t tpr13 = w[A733_DRAM_TPR13];
	unsigned int p;

	if (w[A733_DRAM_TYPE] != PARA_TYPE_LPDDR5) {
		dram_fail(d, "DRAM: only LPDDR5 is supported, type",
			  w[A733_DRAM_TYPE]);
		return -1;
	}

	if (!(tpr13 & TPR13_SKIP_SCAN) || !(tpr13 & TPR13_FOUR_PSTATES) ||
	    !(tpr13 & TPR13_DUAL_CHANNEL) || (tpr13 & TPR13_LOW_POWER)) {
		dram_fail(d, "DRAM: unsupported feature flags", tpr13);
		return -1;
	}

	/* One rank per channel is described in the specification only. */
	if ((w[A733_DRAM_PARA2] & 0xf) != 1 || !(w[A733_DRAM_PARA2] & 0x1000)) {
		dram_fail(d, "DRAM: unsupported width or rank count",
			  w[A733_DRAM_PARA2]);
		return -1;
	}

	/* Only the first table of pin swaps is known. */
	if ((w[25] >> 16) & 0xf) {
		dram_fail(d, "DRAM: unknown pin swap table", w[25]);
		return -1;
	}

	if (w[A733_DRAM_CLK] % 24) {
		dram_fail(d, "DRAM: clock is not a multiple of 24 MHz",
			  w[A733_DRAM_CLK]);
		return -1;
	}

	d->pstates = PSTATES;
	for (p = 0; p < PSTATES; p++) {
		d->divider[p] = (w[24] >> (8 * p)) & 0x1f;
		d->mhz[p] = (uint16_t)(w[A733_DRAM_CLK] * 4 /
				       (d->divider[p] + 1u));
		d->freq[p] = freq_lookup(d->mhz[p]);
		if (!d->freq[p]) {
			dram_fail(d, "DRAM: no settings for frequency (MHz)",
				  d->mhz[p]);
			return -1;
		}
	}

	if (!d->freq[0]->ctl_rfsh) {
		dram_fail(d, "DRAM: frequency not usable as Pstate 0 (MHz)",
			  d->mhz[0]);
		return -1;
	}

	return 0;
}

/*
 * Size in MiB from the geometry: column, row and bank address bits, two
 * bytes per word, ranks and channels; times three quarters when flagged.
 */
uint32_t dram_para_size_mib(const struct a733_dram_para *para)
{
	uint32_t para1 = para->word[A733_DRAM_PARA1];
	uint32_t para2 = para->word[A733_DRAM_PARA2];
	uint32_t tpr13 = para->word[A733_DRAM_TPR13];
	unsigned int bits;
	uint32_t mib;

	bits = para1 & 0xf;			/* column */
	bits += (para1 >> 4) & 0xff;		/* row */
	bits += ((para1 >> 12) & 0x3) + 2;	/* bank */
	bits += 1;				/* 16-bit words */
	bits += (para2 & 0x1000) ? 1 : 0;	/* ranks */
	bits += (tpr13 & TPR13_DUAL_CHANNEL) ? 1 : 0;

	if (bits < 20 || bits > 20 + 31)
		return 0;

	mib = 1u << (bits - 20);
	if (tpr13 & TPR13_THREE_QUARTER)
		mib = mib / 4 * 3;

	return mib;
}
