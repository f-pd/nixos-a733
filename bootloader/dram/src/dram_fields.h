/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Names of the per-frequency table fields. A field is named after the first
 * register it is written to: FC_<controller offset>, F_<step>_<PHY address>.
 */
#ifndef DRAM_FIELDS_H
#define DRAM_FIELDS_H

/* Indices into struct dram_freq_cfg.ctl[] */
enum {
	FC_000,
	FC_004,
	FC_008,
	FC_00C,
	FC_010,
	FC_014,
	FC_018,
	FC_01C,
	FC_024,
	FC_038,
	FC_05C,
	FC_060,
	FC_064,
	FC_D04,
	FC_D08,
	FC_580,
	FC_588,
	FC_600,
	FC_604,
	FC_608,
	FC_650,
	FC_800,
	FC_804,
	FC_808,
	FC_COUNT,
};

/* Indices into struct dram_freq_cfg.phy[] */
enum {
	F_CFG_2004C,
	F_CFG_90801,
	F_CFG_1000F,
	F_CFG_2004A,
	F_POST_908F0,
	F_POST_908F1,
	F_POST_908F3,
	F_POST_908F4,
	F_POST_4107C,
	F_POST_41084,
	F_POST_1000F,
	F_POST_2004A,
	F_POST_2004C,
	F_MSG_58002,
	F_MSG_58003,
	F_MSG_5800E,
	F_MSG_58041,
	F_MSG_58081,
	F_MSG_58082,
	F_COUNT,
};

#endif
