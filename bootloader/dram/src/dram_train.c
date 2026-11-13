// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Training of one Pstate: message block, pin swap, firmware run, and the
 * steps after it. Read-back of the trained values.
 */

#include "dram_internal.h"

enum msg_kind {
	MSG_VAL,	/* arg repeated count times */
	MSG_FIELD,	/* field arg of the frequency row, count times */
	MSG_PARA_BYTE,	/* low byte of parameter word arg, in both bytes */
	MSG_PAYLOAD,	/* count words of the payload at offset arg */
	MSG_PAYLOAD_NZ,	/* the same on Pstates 1 to 3, zeros on Pstate 0 */
	MSG_PSTATE,	/* arg, with the Pstate in bits 10 and 11 */
};

struct msg_item {
	uint8_t kind;
	uint16_t count;
	uint32_t arg;
};

/*
 * The PHY data memory from its start: the message block for the firmware,
 * then the firmware data. Everything after the last item is zeroed.
 */
static const struct msg_item msg_block[] = {
	{ MSG_VAL, 2, 0 },
	{ MSG_FIELD, 1, F_MSG_58002 },
	{ MSG_FIELD, 1, F_MSG_58003 },
	{ MSG_VAL, 2, 0x0004 },
	{ MSG_VAL, 2, 0 },
	{ MSG_VAL, 1, 0x125f },
	{ MSG_VAL, 1, 0x00ff },
	{ MSG_VAL, 1, 0 },
	{ MSG_VAL, 1, 0x0002 },
	{ MSG_VAL, 2, 0 },
	{ MSG_FIELD, 1, F_MSG_5800E },
	{ MSG_VAL, 3, 0 },
	{ MSG_VAL, 1, 0x0310 },
	{ MSG_VAL, 12, 0 },
	{ MSG_VAL, 1, 0x1000 },
	{ MSG_PAYLOAD, 9, PAYLOAD_MSG_A },
	{ MSG_VAL, 4, 0 },
	{ MSG_VAL, 2, 0x8080 },
	{ MSG_VAL, 2, 0x8888 },
	{ MSG_VAL, 2, 0x0606 },
	{ MSG_VAL, 2, 0x5454 },
	{ MSG_PARA_BYTE, 2, 15 },
	{ MSG_VAL, 2, 0x4444 },
	{ MSG_VAL, 2, 0 },
	{ MSG_PARA_BYTE, 4, 18 },
	{ MSG_VAL, 2, 0 },
	{ MSG_FIELD, 2, F_MSG_58041 },
	{ MSG_VAL, 2, 0x1c1c },
	{ MSG_VAL, 2, 0x1010 },
	{ MSG_VAL, 2, 0x0202 },
	{ MSG_VAL, 12, 0 },
	{ MSG_VAL, 2, 0x0404 },
	{ MSG_VAL, 14, 0 },
	{ MSG_VAL, 2, 0x6060 },
	{ MSG_PAYLOAD_NZ, 13, PAYLOAD_MSG_B },
	{ MSG_VAL, 1, 0x002e },
	{ MSG_VAL, 1, 0x0050 },
	{ MSG_VAL, 2, 0 },
	{ MSG_PSTATE, 1, 0x0058 },
	{ MSG_PSTATE, 1, 0x0287 },
	{ MSG_VAL, 6, 0 },
	{ MSG_VAL, 1, 0x0f01 },
	{ MSG_FIELD, 1, F_MSG_58081 },
	{ MSG_FIELD, 1, F_MSG_58082 },
	{ MSG_VAL, 385, 0 },
	{ MSG_VAL, 1, 0x0500 },
	{ MSG_VAL, 13, 0 },
	{ MSG_VAL, 1, 0x715d },
	{ MSG_VAL, 1, 0x00ce },
	{ MSG_VAL, 9, 0 },
	{ MSG_PAYLOAD, 16, PAYLOAD_MSG_C },
	{ MSG_PAYLOAD, 9, PAYLOAD_MSG_D },
	{ MSG_PAYLOAD, PAYLOAD_LP5_DMEM_WORDS, PAYLOAD_LP5_DMEM },
};

void phy_write_msg_block(struct dram *d, unsigned int pstate)
{
	const struct dram_freq_cfg *f = d->freq[pstate];
	uint32_t reg = PHY_DMEM;
	unsigned int i;
	uint16_t val;

	phy_wr(d, PHY_MUX, 0);
	udelay(d, 1);

	for (i = 0; i < ARRAY_SIZE(msg_block); i++) {
		const struct msg_item *m = &msg_block[i];

		switch (m->kind) {
		case MSG_PAYLOAD:
			phy_load(d, reg, m->count, m->arg);
			break;
		case MSG_PAYLOAD_NZ:
			if (pstate)
				phy_load(d, reg, m->count, m->arg);
			else
				phy_fill(d, reg, m->count, 0);
			break;
		case MSG_FIELD:
			phy_fill(d, reg, m->count, f->phy[m->arg]);
			break;
		case MSG_PARA_BYTE:
			val = d->para->word[m->arg] & 0xff;
			phy_fill(d, reg, m->count, (uint16_t)(val << 8 | val));
			break;
		case MSG_PSTATE:
			phy_fill(d, reg, m->count,
				 (uint16_t)(m->arg | (pstate << 10)));
			break;
		default:
			phy_fill(d, reg, m->count, m->arg);
			break;
		}
		reg += m->count;
	}

	phy_fill(d, reg, PHY_DMEM_END - reg, 0);

	phy_wr(d, PHY_MUX, 1);
	phy_wr(d, PHY_MUX, 0);
}

/* Board routing of the Orange Pi Zero 3W: pin swap table 0. */
static const uint8_t swap_ac[AC_GROUPS][7] = {
	{ 3, 6, 4, 0, 2, 5, 1 },
	{ 3, 0, 6, 4, 2, 5, 1 },
};

static const uint8_t swap_dq[BYTE_LANES][8] = {
	{ 4, 3, 5, 7, 0, 1, 6, 2 },
	{ 3, 2, 1, 0, 5, 7, 6, 4 },
	{ 1, 4, 5, 2, 7, 6, 0, 3 },
	{ 6, 7, 3, 0, 4, 5, 1, 2 },
};

void phy_write_swap(struct dram *d)
{
	unsigned int ac, lane, bit;

	for (ac = 0; ac < AC_GROUPS; ac++)
		for (bit = 0; bit < ARRAY_SIZE(swap_ac[ac]); bit++)
			phy_wr(d, 0x30090 + ac * LANE_STRIDE + bit,
			       swap_ac[ac][bit]);

	for (bit = 0; bit < ARRAY_SIZE(swap_dq[0]); bit++)
		for (lane = 0; lane < BYTE_LANES; lane++)
			phy_wr(d, 0x10080 + lane * LANE_STRIDE + bit,
			       swap_dq[lane][bit]);

	phy_wr(d, PHY_MUX, 1);
}

/*
 * Start the firmware and take its one message from the mailbox. Anything
 * but "training completed" is a failure.
 */
int phy_run_firmware(struct dram *d, unsigned int pstate)
{
	uint16_t msg;

	phy_wr(d, PHY_MUX, 1);
	phy_wr(d, PHY_FW_CTRL, 9);
	phy_wr(d, PHY_FW_CTRL, 1);
	phy_wr(d, PHY_FW_CTRL, 0);
	phy_wr(d, PHY_MSG_ACK, 1);
	phy_wr(d, PHY_MSG_ACK2, 1);

	phy_wait(d, PHY_MAILBOX_ST, 1, 0);
	msg = phy_rd(d, PHY_MSG_LO);
	(void)phy_rd(d, PHY_MSG_HI);
	dram_log(d, "Training result is =", msg);

	phy_wr(d, PHY_MSG_ACK, 0);
	phy_wait(d, PHY_MAILBOX_ST, 1, 1);
	phy_wr(d, PHY_MSG_ACK, 1);
	phy_wr(d, PHY_FW_CTRL, 1);

	if (msg != PHY_TRAIN_DONE) {
		dram_fail(d, "DRAM: training failed on Pstate", pstate);
		return -1;
	}

	dram_log(d, "DRAM Pstate trained, frequency (MHz)", d->mhz[pstate]);
	return 0;
}

/*
 * After training: complete the save list of the Pstate (the remaining head
 * records, a copy of the sequence table, more of the main part) and tell
 * the PHY where the parts are.
 */
void phy_post_train(struct dram *d, unsigned int pstate)
{
	uint32_t area = PHY_SAVE_AREA(pstate);
	uint16_t records;

	phy_wr(d, PHY_MUX, 0);
	udelay(d, 1);

	phy_save_seek(d, area + PHY_SAVE_HEAD_POST);
	phy_run_groups(d, phy_post_head, phy_post_head_count, pstate);

	phy_save_seek(d, area + PHY_SAVE_SEQ);
	phy_run_groups(d, phy_post_seq, phy_post_seq_count, pstate);

	phy_save_seek(d, d->save_main[pstate]);
	phy_run_groups(d, phy_post_main, phy_post_main_count, pstate);
	phy_save_flush(d);
	d->save_main[pstate] = d->save.ptr;

	records = (uint16_t)((d->save.ptr - (area + PHY_SAVE_MAIN)) / 4);

	/* Start and length, in records, of the parts of the save list */
	phy_wr(d, 0xc0110 + pstate, (uint16_t)pstate);
	phy_wr(d, 0xc0108, PHY_SAVE_SEQ / 4);
	phy_wr(d, 0xc010c, 0x00e0);
	phy_save_seek(d, area + PHY_SAVE_HEAD_LAST);
	phy_save_record(d, 0xc010e, records, records, 0x08);
	phy_wr(d, 0xc0109, PHY_SAVE_HEAD / 4);
	phy_wr(d, 0xc010d, PHY_SAVE_HEAD_RECORDS);
	phy_wr(d, 0xc010a, PHY_SAVE_MAIN / 4);
	phy_wr(d, 0xc010e, records);
	phy_wr(d, 0xc010b, 0x0287);
}

/*
 * Read the trained values of every byte lane and mode registers 14 and 15
 * of both channels and ranks into the parameter block.
 */
void phy_read_back(struct dram *d)
{
	uint32_t *w = d->para->word;
	unsigned int lane, bit, half, ch, rank, n = 0;
	uint32_t mr14 = 0, mr15 = 0;

	phy_wr(d, PHY_MUX, 0);

	for (n = A733_DRAM_TRAINED; n < A733_DRAM_MR14; n++)
		w[n] = 0;

	n = 0;
	for (lane = 0; lane < BYTE_LANES; lane++) {
		for (bit = 0; bit < LANE_BITS; bit++) {
			for (half = 0; half < 2; half++, n++) {
				uint32_t reg = 0x1004e + lane * LANE_STRIDE +
					       bit * BIT_STRIDE + half;
				uint32_t val = phy_rd(d, reg) & 0x7f;

				w[A733_DRAM_TRAINED + n / 4] |=
					val << (8 * (n % 4));
			}
		}
	}

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_mr_write(d, ch, 16, 5);

	for (ch = 0; ch < CHANNELS; ch++)
		for (rank = 0; rank < RANKS; rank++)
			mr14 |= ctl_mr_read(d, ch, rank, 14) <<
				(8 * (ch * RANKS + rank));
	for (ch = 0; ch < CHANNELS; ch++)
		for (rank = 0; rank < RANKS; rank++)
			mr15 |= ctl_mr_read(d, ch, rank, 15) <<
				(8 * (ch * RANKS + rank));

	for (ch = 0; ch < CHANNELS; ch++)
		ctl_mr_write(d, ch, 16, 4);

	phy_wr(d, PHY_MUX, 1);

	w[A733_DRAM_MR14] = mr14;
	w[A733_DRAM_MR15] = mr15;
}
