// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * DRAM initialisation for the Allwinner A733: the sequence.
 *
 * Written from docs/dram-init-spec.md and the reference scripts in
 * docs/dram-init/. Nothing here has run on hardware yet, see README.md.
 */

#include "dram_internal.h"

/* Pstates are trained in this order, the one the system runs at last. */
static const uint8_t train_order[PSTATES] = { 1, 2, 3, 0 };

static int dram_train_pstate(struct dram *d, unsigned int pstate)
{
	phy_config_pstate(d, pstate);

	ctl_select_pstate(d, pstate);
	dram_clock_set_pstate(d, pstate);

	phy_write_msg_block(d, pstate);
	phy_write_swap(d);

	if (phy_run_firmware(d, pstate))
		return -1;

	phy_post_train(d, pstate);
	return 0;
}

#define MEM_TEST_WORDS	16

/*
 * Write a counting pattern at the base of memory and another one half way
 * up, at most 2 GiB above the base, then read both back.
 */
static int dram_mem_test(struct dram *d, uint32_t size_mib)
{
	uint32_t half_mib = (size_mib > 4096 ? 4096 : size_mib) / 2;
	uint32_t top = DRAM_BASE + (half_mib << 20);
	unsigned int i;

	for (i = 0; i < MEM_TEST_WORDS; i++) {
		wr32(d, DRAM_BASE + 4 * i, 0x01234567 + i);
		wr32(d, top + 4 * i, 0xfedcba98 + i);
	}

	for (i = 0; i < MEM_TEST_WORDS; i++)
		if (rd32(d, DRAM_BASE + 4 * i) != 0x01234567 + i ||
		    rd32(d, top + 4 * i) != 0xfedcba98 + i)
			return -1;

	return 0;
}

uint32_t a733_dram_init_para(const struct a733_dram_ops *ops,
			     const uint8_t *payload, size_t payload_len,
			     struct a733_dram_para *para)
{
	struct dram dram = {
		.ops = ops,
		.para = para,
		.payload = payload,
		.payload_len = payload_len,
	};
	struct dram *d = &dram;
	unsigned int ch, i;
	uint32_t size_mib;

	if (!payload || (payload_len < A733_DRAM_PAYLOAD_SIZE &&
			 payload_len != a733_dram_payload_packed_size())) {
		dram_fail(d, "DRAM: firmware payload missing or too short",
			  (uint32_t)payload_len);
		return 0;
	}

	if (dram_para_check(d))
		return 0;

	setbits32(d, SYSCFG_BASE + 0x160, 1u << 8);
	clrbits32(d, SYSCFG_BASE + 0x168, 0xff);

	if (dram_power(d))
		return 0;
	dram_log(d, "DRAM CLK (MHz) =", para->word[A733_DRAM_CLK]);
	dram_log(d, "DRAM Type (8:LPDDR4,9:LPDDR5) =", para->word[A733_DRAM_TYPE]);

	dram_clocks_init(d);

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_init(d, ch);
	dram_glue_release_resets(d);
	if (d->err)
		return 0;

	phy_init_common(d);
	phy_load_firmware(d);
	for (i = 0; i < d->pstates; i++)
		if (dram_train_pstate(d, train_order[i]) || d->err)
			return 0;
	phy_finish(d);

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_adjust_timing(d, ch);
	ctl_handover(d);
	ctl_remap(d);
	ctl_dfs_setup(d);
	phy_read_back(d);
	if (d->err)
		return 0;

	size_mib = dram_para_size_mib(para);
	para->word[A733_DRAM_PARA2] = (para->word[A733_DRAM_PARA2] & 0xffff) |
				      (size_mib << 16);
	dram_log(d, "DRAM SIZE (MiB) =", size_mib);

	if (!size_mib || dram_mem_test(d, size_mib)) {
		dram_fail(d, "DRAM: simple test failed, size (MiB)", size_mib);
		return 0;
	}
	dram_log(d, "DRAM simple test OK, size (MiB)", size_mib);

	return size_mib;
}

uint32_t a733_dram_init(const struct a733_dram_ops *ops,
			const uint8_t *payload, size_t payload_len,
			struct a733_dram_para *para)
{
	struct a733_dram_para local;

	if (!para)
		para = &local;

	a733_dram_select_para(ops->strap(ops->ctx), para);

	return a733_dram_init_para(ops, payload, payload_len, para);
}
