// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * PHY register tables for the common setup, the per-Pstate configuration
 * and the post-training step.
 *
 * The values are the register values documented in docs/dram-init/ops-*.tsv.
 * See ../README.md for which of them are per-frequency tables.
 */

#include "dram_internal.h"

static const struct phy_op phy_cfg_head_0[] = {
	{ 0x90802, 0x0000, PHY_SAVE },
	{ 0x2004c, F_CFG_2004C, PHY_VAR },
	{ 0x2004d, 0x0000, 0 },
	{ 0x20002, 0x0002, PHY_SAVE },
	{ 0x20000, 0x0002, PHY_SAVE },
	{ 0x90801, F_CFG_90801, PHY_VAR|PHY_SAVE },
	{ 0x90809, 0x6800, PHY_SAVE },
};

const struct phy_group phy_cfg_head[] = {
	{ phy_cfg_head_0, 7, PHY_LOOP_ONCE },
};
const unsigned int phy_cfg_head_count = 1;

static const struct phy_op phy_cfg_main_0[] = {
	{ 0x1005e, 0x0366, PHY_SAVE },
	{ 0x10060, 0x0366, PHY_SAVE },
	{ 0x10062, 0x0366, PHY_SAVE },
	{ 0x10064, 0x0366, PHY_SAVE },
	{ 0x1005f, 0x0366, PHY_SAVE },
	{ 0x10061, 0x0366, PHY_SAVE },
	{ 0x10063, 0x0366, PHY_SAVE },
	{ 0x10065, 0x0366, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_1[] = {
	{ 0x10005, 0x0000, PHY_SAVE },
	{ 0x1000b, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_2[] = {
	{ 0x20007, 0x0000, PHY_SAVE },
	{ 0x20013, 0x002c, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_3[] = {
	{ 0x30038, 0x0003, PHY_SAVE },
	{ 0x30039, 0x0003, PHY_SAVE },
	{ 0x3003a, 0x0003, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_4[] = {
	{ 0x10038, 0x0003, PHY_SAVE },
	{ 0x1003a, 0x0003, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_5[] = {
	{ 0x1003b, 0x0003, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_6[] = {
	{ 0x10009, 0x0000, PHY_SAVE },
	{ 0x10037, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_7[] = {
	{ 0x10004, 0x0000, PHY_SAVE },
	{ 0x10003, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_8[] = {
	{ 0x20004, 0, PHY_QFREQ|PHY_SAVE },
};
static const struct phy_op phy_cfg_main_9[] = {
	{ 0x30050, 0x0035, PHY_SAVE },
	{ 0x30051, 0x0035, PHY_SAVE },
	{ 0x30052, 0x0035, PHY_SAVE },
	{ 0x30053, 0x0035, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_10[] = {
	{ 0x1004e, 0x0035, PHY_SAVE },
	{ 0x1004f, 0x0035, PHY_SAVE },
	{ 0x10050, 0x0035, PHY_SAVE },
	{ 0x10051, 0x0035, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_11[] = {
	{ 0x30030, 0x0000, PHY_SAVE },
	{ 0x30031, 0x0000, PHY_SAVE },
	{ 0x30035, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_12[] = {
	{ 0x10030, 0x0000, PHY_SAVE },
	{ 0x10035, 0x0000, PHY_SAVE },
	{ 0x10036, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_13[] = {
	{ 0x3003c, 0x0005, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_14[] = {
	{ 0x1003c, 0x0005, PHY_SAVE },
	{ 0x1003d, 0x0005, PHY_SAVE },
	{ 0x1003e, 0x0005, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_15[] = {
	{ 0x20003, 0x0001, PHY_SAVE },
	{ 0x20001, 0x1122, PHY_SAVE },
	{ 0x20009, 0x0000, PHY_SAVE },
	{ 0x20008, 0x0000, PHY_SAVE },
	{ 0x200d9, 0x0001, PHY_SAVE },
	{ 0x20014, 0x1301, PHY_SAVE },
	{ 0x9080a, 0x1300, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_16[] = {
	{ 0x10040, 0x0f0f, PHY_SAVE },
	{ 0x10042, 0x0f0f, PHY_SAVE },
	{ 0x9080d, 0x0000, PHY_SAVE },
	{ 0x10043, 0x0000, PHY_SAVE },
	{ 0x10044, 0x0f0f, PHY_SAVE },
	{ 0x10045, 0x0f0f, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_17[] = {
	{ 0x30040, 0x0f0f, PHY_SAVE },
	{ 0x30041, 0x0f0f, PHY_SAVE },
	{ 0x30042, 0x0e0e, PHY_SAVE },
	{ 0x30043, 0x0e0e, PHY_SAVE },
	{ 0x30330, 0x0033, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_18[] = {
	{ 0x20331, 0x0033, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_19[] = {
	{ 0x10048, 0x0e00, PHY_SAVE },
	{ 0x1004a, 0x0e00, PHY_SAVE },
	{ 0x1004b, 0x0e00, PHY_SAVE },
	{ 0x1004c, 0x0800, PHY_SAVE },
	{ 0x1004d, 0x0800, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_20[] = {
	{ 0x30048, 0x0c00, PHY_SAVE },
	{ 0x30049, 0x0c00, PHY_SAVE },
	{ 0x3004a, 0x0e00, PHY_SAVE },
	{ 0x3004b, 0x0e00, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_21[] = {
	{ 0x30033, 0x0000, PHY_SAVE },
	{ 0x30034, 0x0000, PHY_SAVE },
	{ 0x3002e, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_22[] = {
	{ 0x10033, 0x0000, PHY_SAVE },
	{ 0x1002e, 0x0000, PHY_SAVE },
	{ 0x1002f, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_23[] = {
	{ 0x20015, 0x0000, 0 },
	{ 0x90806, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_24[] = {
	{ 0x100e8, 0x0000, PHY_SAVE },
	{ 0x100e9, 0x0035, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_25[] = {
	{ 0x10001, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_26[] = {
	{ 0x20012, 0xa1a1, PHY_SAVE },
	{ 0x20017, 0x0040, PHY_SAVE },
	{ 0x2000a, 0x0040, PHY_SAVE },
	{ 0x20186, 0x00a1, PHY_SAVE },
	{ 0x20187, 0x0040, PHY_SAVE },
	{ 0x20010, 0x0050, PHY_SAVE },
	{ 0x20011, 0x000f, PHY_SAVE },
	{ 0x9080b, 0x000f, PHY_SAVE },
	{ 0x9080c, 0x000f, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_27[] = {
	{ 0x100a5, 0x0001, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_28[] = {
	{ 0x10014, 0x3232, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_29[] = {
	{ 0x1000f, F_CFG_1000F, PHY_VAR },
};
static const struct phy_op phy_cfg_main_30[] = {
	{ 0x20035, 0x0c08, PHY_SAVE },
	{ 0x20036, 0x0c08, PHY_SAVE },
	{ 0x20037, 0x0414, PHY_SAVE },
	{ 0x20038, 0x1918, PHY_SAVE },
	{ 0x20039, 0x0c10, PHY_SAVE },
	{ 0x2003a, 0x0c10, PHY_SAVE },
	{ 0x2003b, 0x041c, PHY_SAVE },
	{ 0x2003c, 0x2920, PHY_SAVE },
	{ 0x2003d, 0x0c04, PHY_SAVE },
	{ 0x2003e, 0x0c04, PHY_SAVE },
	{ 0x2003f, 0x0410, PHY_SAVE },
	{ 0x20040, 0x1114, PHY_SAVE },
	{ 0x2002c, 0x082f, PHY_SAVE },
	{ 0x2002d, 0x082f, PHY_SAVE },
	{ 0x20030, 0x082f, PHY_SAVE },
	{ 0x2002e, 0x0817, PHY_SAVE },
	{ 0x2002f, 0x0817, PHY_SAVE },
	{ 0x2000c, 0x0000, PHY_SAVE },
	{ 0x2001b, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_31[] = {
	{ 0x10007, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_cfg_main_32[] = {
	{ 0xc0080, 0x0003, 0 },
	{ 0x2004a, F_CFG_2004A, PHY_VAR|PHY_SAVE },
	{ 0x2004b, 0x123e, PHY_SAVE },
	{ 0x2004c, F_CFG_2004C, PHY_VAR|PHY_SAVE },
};

const struct phy_group phy_cfg_main[] = {
	{ phy_cfg_main_0, 8, PHY_LOOP_LANE },
	{ phy_cfg_main_1, 2, PHY_LOOP_LANE },
	{ phy_cfg_main_2, 2, PHY_LOOP_ONCE },
	{ phy_cfg_main_3, 3, PHY_LOOP_AC },
	{ phy_cfg_main_4, 2, PHY_LOOP_LANE },
	{ phy_cfg_main_5, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_6, 2, PHY_LOOP_LANE },
	{ phy_cfg_main_7, 2, PHY_LOOP_LANE },
	{ phy_cfg_main_8, 1, PHY_LOOP_ONCE },
	{ phy_cfg_main_9, 4, PHY_LOOP_AC },
	{ phy_cfg_main_10, 4, PHY_LOOP_LANE_BIT },
	{ phy_cfg_main_11, 3, PHY_LOOP_AC },
	{ phy_cfg_main_12, 3, PHY_LOOP_LANE },
	{ phy_cfg_main_13, 1, PHY_LOOP_AC },
	{ phy_cfg_main_14, 3, PHY_LOOP_LANE },
	{ phy_cfg_main_15, 7, PHY_LOOP_ONCE },
	{ phy_cfg_main_16, 6, PHY_LOOP_LANE },
	{ phy_cfg_main_17, 5, PHY_LOOP_AC },
	{ phy_cfg_main_18, 1, PHY_LOOP_ONCE },
	{ phy_cfg_main_19, 5, PHY_LOOP_LANE },
	{ phy_cfg_main_20, 4, PHY_LOOP_AC },
	{ phy_cfg_main_21, 3, PHY_LOOP_AC },
	{ phy_cfg_main_22, 3, PHY_LOOP_LANE },
	{ phy_cfg_main_23, 2, PHY_LOOP_ONCE },
	{ phy_cfg_main_24, 2, PHY_LOOP_LANE },
	{ phy_cfg_main_25, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_26, 9, PHY_LOOP_ONCE },
	{ phy_cfg_main_27, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_28, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_29, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_30, 19, PHY_LOOP_ONCE },
	{ phy_cfg_main_31, 1, PHY_LOOP_LANE },
	{ phy_cfg_main_32, 4, PHY_LOOP_ONCE },
};
const unsigned int phy_cfg_main_count = 33;

static const struct phy_op phy_post_head_0[] = {
	{ 0x908f0, F_POST_908F0, PHY_VAR|PHY_SAVE },
	{ 0x908f1, F_POST_908F1, PHY_VAR|PHY_SAVE },
	{ 0x908f2, 0x0000, PHY_SAVE },
	{ 0x908f3, F_POST_908F3, PHY_VAR|PHY_SAVE },
	{ 0x908f4, F_POST_908F4, PHY_VAR|PHY_SAVE },
	{ 0x908f5, 0x0000, PHY_SAVE },
	{ 0x908f6, 0x00b0, PHY_SAVE },
	{ 0x908f7, 0x0000, PHY_SAVE },
};

const struct phy_group phy_post_head[] = {
	{ phy_post_head_0, 8, PHY_LOOP_ONCE },
};
const unsigned int phy_post_head_count = 1;

static const struct phy_op phy_post_seq_0[] = {
	{ 0x41008, 0xc9d8, PHY_SAVE },
	{ 0x41009, 0x0000, PHY_SAVE },
	{ 0x4100a, 0x0000, PHY_SAVE },
	{ 0x4100b, 0x0000, PHY_SAVE },
	{ 0x4100c, 0xc808, PHY_SAVE },
	{ 0x4100d, 0x0000, PHY_SAVE },
	{ 0x4100e, 0x0000, PHY_SAVE },
	{ 0x4100f, 0x0000, PHY_SAVE },
	{ 0x41010, 0x0000, PHY_SAVE },
	{ 0x41011, 0x0000, PHY_SAVE },
	{ 0x41012, 0x0000, PHY_SAVE },
	{ 0x41013, 0x2b00, PHY_SAVE },
	{ 0x41014, 0x0000, PHY_SAVE },
	{ 0x41015, 0x0000, PHY_SAVE },
	{ 0x41016, 0x0000, PHY_SAVE },
	{ 0x41017, 0x0000, PHY_SAVE },
	{ 0x41018, 0xc958, PHY_SAVE },
	{ 0x41019, 0x0000, PHY_SAVE },
	{ 0x4101a, 0x0000, PHY_SAVE },
	{ 0x4101b, 0x0000, PHY_SAVE },
	{ 0x4101c, 0xce08, PHY_SAVE },
	{ 0x4101d, 0x0000, PHY_SAVE },
	{ 0x4101e, 0x0000, PHY_SAVE },
	{ 0x4101f, 0x0000, PHY_SAVE },
	{ 0x41020, 0x0000, PHY_SAVE },
	{ 0x41021, 0x0000, PHY_SAVE },
	{ 0x41022, 0x0000, PHY_SAVE },
	{ 0x41023, 0x2b00, PHY_SAVE },
	{ 0x41024, 0x0000, PHY_SAVE },
	{ 0x41025, 0x0000, PHY_SAVE },
	{ 0x41026, 0x0000, PHY_SAVE },
	{ 0x41027, 0x0000, PHY_SAVE },
	{ 0x41028, 0xc0d8, PHY_SAVE },
	{ 0x41029, 0x0000, PHY_SAVE },
	{ 0x4102a, 0x0000, PHY_SAVE },
	{ 0x4102b, 0x0000, PHY_SAVE },
	{ 0x4102c, 0xc048, PHY_SAVE },
	{ 0x4102d, 0x0000, PHY_SAVE },
	{ 0x4102e, 0x0000, PHY_SAVE },
	{ 0x4102f, 0x0000, PHY_SAVE },
	{ 0x41030, 0x0000, PHY_SAVE },
	{ 0x41031, 0x0000, PHY_SAVE },
	{ 0x41032, 0x0000, PHY_SAVE },
	{ 0x41033, 0x2b00, PHY_SAVE },
	{ 0x41034, 0x0000, PHY_SAVE },
	{ 0x41035, 0x0000, PHY_SAVE },
	{ 0x41036, 0x0000, PHY_SAVE },
	{ 0x41037, 0x0000, PHY_SAVE },
	{ 0x41038, 0xc158, PHY_SAVE },
	{ 0x41039, 0x0000, PHY_SAVE },
	{ 0x4103a, 0x0000, PHY_SAVE },
	{ 0x4103b, 0x0000, PHY_SAVE },
	{ 0x4103c, 0xc448, PHY_SAVE },
	{ 0x4103d, 0x0000, PHY_SAVE },
	{ 0x4103e, 0x0000, PHY_SAVE },
	{ 0x4103f, 0x0000, PHY_SAVE },
	{ 0x41040, 0x0000, PHY_SAVE },
	{ 0x41041, 0x0000, PHY_SAVE },
	{ 0x41042, 0x0000, PHY_SAVE },
	{ 0x41043, 0x2b00, PHY_SAVE },
	{ 0x41044, 0x0000, PHY_SAVE },
	{ 0x41045, 0x0000, PHY_SAVE },
	{ 0x41046, 0x0000, PHY_SAVE },
	{ 0x41047, 0x0000, PHY_SAVE },
	{ 0x41048, 0xc1d8, PHY_SAVE },
	{ 0x41049, 0x0000, PHY_SAVE },
	{ 0x4104a, 0x0000, PHY_SAVE },
	{ 0x4104b, 0x0000, PHY_SAVE },
	{ 0x4104c, 0xc308, PHY_SAVE },
	{ 0x4104d, 0x0000, PHY_SAVE },
	{ 0x4104e, 0x0000, PHY_SAVE },
	{ 0x4104f, 0x0000, PHY_SAVE },
	{ 0x41050, 0x0000, PHY_SAVE },
	{ 0x41051, 0x0000, PHY_SAVE },
	{ 0x41052, 0x0000, PHY_SAVE },
	{ 0x41053, 0x2b00, PHY_SAVE },
	{ 0x41054, 0x0000, PHY_SAVE },
	{ 0x41055, 0x0000, PHY_SAVE },
	{ 0x41056, 0x0000, PHY_SAVE },
	{ 0x41057, 0x0000, PHY_SAVE },
	{ 0x41058, 0xc558, PHY_SAVE },
	{ 0x41059, 0x0000, PHY_SAVE },
	{ 0x4105a, 0x0000, PHY_SAVE },
	{ 0x4105b, 0x0000, PHY_SAVE },
	{ 0x4105c, 0xea08, PHY_SAVE },
	{ 0x4105d, 0x0000, PHY_SAVE },
	{ 0x4105e, 0x0000, PHY_SAVE },
	{ 0x4105f, 0x0000, PHY_SAVE },
	{ 0x41060, 0x0000, PHY_SAVE },
	{ 0x41061, 0x0000, PHY_SAVE },
	{ 0x41062, 0x0000, PHY_SAVE },
	{ 0x41063, 0x2b00, PHY_SAVE },
	{ 0x41064, 0x0000, PHY_SAVE },
	{ 0x41065, 0x0000, PHY_SAVE },
	{ 0x41066, 0x0000, PHY_SAVE },
	{ 0x41067, 0x0000, PHY_SAVE },
	{ 0x41068, 0xc5d8, PHY_SAVE },
	{ 0x41069, 0x0000, PHY_SAVE },
	{ 0x4106a, 0x0000, PHY_SAVE },
	{ 0x4106b, 0x0000, PHY_SAVE },
	{ 0x4106c, 0xc108, PHY_SAVE },
	{ 0x4106d, 0x0000, PHY_SAVE },
	{ 0x4106e, 0x0000, PHY_SAVE },
	{ 0x4106f, 0x0000, PHY_SAVE },
	{ 0x41070, 0x0000, PHY_SAVE },
	{ 0x41071, 0x0000, PHY_SAVE },
	{ 0x41072, 0x0000, PHY_SAVE },
	{ 0x41073, 0x2b00, PHY_SAVE },
	{ 0x41074, 0x0000, PHY_SAVE },
	{ 0x41075, 0x0000, PHY_SAVE },
	{ 0x41076, 0x0000, PHY_SAVE },
	{ 0x41077, 0x0000, PHY_SAVE },
	{ 0x41078, 0x48d8, PHY_SAVE },
	{ 0x41079, 0x0000, PHY_SAVE },
	{ 0x4107a, 0x0000, PHY_SAVE },
	{ 0x4107b, 0x0000, PHY_SAVE },
	{ 0x4107c, F_POST_4107C, PHY_VAR|PHY_SAVE },
	{ 0x4107d, 0x0000, PHY_SAVE },
	{ 0x4107e, 0x0000, PHY_SAVE },
	{ 0x4107f, 0x0000, PHY_SAVE },
	{ 0x41080, 0x88d8, PHY_SAVE },
	{ 0x41081, 0x0000, PHY_SAVE },
	{ 0x41082, 0x0000, PHY_SAVE },
	{ 0x41083, 0x0000, PHY_SAVE },
	{ 0x41084, F_POST_41084, PHY_VAR|PHY_SAVE },
	{ 0x41085, 0x0000, PHY_SAVE },
	{ 0x41086, 0x0000, PHY_SAVE },
	{ 0x41087, 0x0000, PHY_SAVE },
	{ 0x41088, 0x0000, PHY_SAVE },
	{ 0x41089, 0x0000, PHY_SAVE },
	{ 0x4108a, 0x0000, PHY_SAVE },
	{ 0x4108b, 0x2b00, PHY_SAVE },
	{ 0x4108c, 0x0000, PHY_SAVE },
	{ 0x4108d, 0x0000, PHY_SAVE },
	{ 0x4108e, 0x0000, PHY_SAVE },
	{ 0x4108f, 0x0000, PHY_SAVE },
	{ 0x41090, 0xca58, PHY_SAVE },
	{ 0x41091, 0x0000, PHY_SAVE },
	{ 0x41092, 0x0000, PHY_SAVE },
	{ 0x41093, 0x0000, PHY_SAVE },
	{ 0x41094, 0xc108, PHY_SAVE },
	{ 0x41095, 0x0000, PHY_SAVE },
	{ 0x41096, 0x0000, PHY_SAVE },
	{ 0x41097, 0x0000, PHY_SAVE },
	{ 0x41098, 0x0000, PHY_SAVE },
	{ 0x41099, 0x0000, PHY_SAVE },
	{ 0x4109a, 0x0000, PHY_SAVE },
	{ 0x4109b, 0x2b00, PHY_SAVE },
	{ 0x4109c, 0x0000, PHY_SAVE },
	{ 0x4109d, 0x0000, PHY_SAVE },
	{ 0x4109e, 0x0000, PHY_SAVE },
	{ 0x4109f, 0x0000, PHY_SAVE },
	{ 0x410a0, 0xcb58, PHY_SAVE },
	{ 0x410a1, 0x0000, PHY_SAVE },
	{ 0x410a2, 0x0000, PHY_SAVE },
	{ 0x410a3, 0x0000, PHY_SAVE },
	{ 0x410a4, 0xc008, PHY_SAVE },
	{ 0x410a5, 0x0000, PHY_SAVE },
	{ 0x410a6, 0x0000, PHY_SAVE },
	{ 0x410a7, 0x0000, PHY_SAVE },
	{ 0x410a8, 0x0000, PHY_SAVE },
	{ 0x410a9, 0x0000, PHY_SAVE },
	{ 0x410aa, 0x0000, PHY_SAVE },
	{ 0x410ab, 0x2b00, PHY_SAVE },
	{ 0x410ac, 0x0000, PHY_SAVE },
	{ 0x410ad, 0x0000, PHY_SAVE },
	{ 0x410ae, 0x0000, PHY_SAVE },
	{ 0x410af, 0x0000, PHY_SAVE },
	{ 0x410b0, 0xd4d8, PHY_SAVE },
	{ 0x410b1, 0x0000, PHY_SAVE },
	{ 0x410b2, 0x0000, PHY_SAVE },
	{ 0x410b3, 0x0000, PHY_SAVE },
	{ 0x410b4, 0xf008, PHY_SAVE },
	{ 0x410b5, 0x0000, PHY_SAVE },
	{ 0x410b6, 0x0000, PHY_SAVE },
	{ 0x410b7, 0x0000, PHY_SAVE },
};

const struct phy_group phy_post_seq[] = {
	{ phy_post_seq_0, 176, PHY_LOOP_ONCE },
};
const unsigned int phy_post_seq_count = 1;

static const struct phy_op phy_post_main_0[] = {
	{ 0x20015, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_post_main_1[] = {
	{ 0x3004a, 0x0000, PHY_SAVE },
	{ 0x3004b, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_post_main_2[] = {
	{ 0x2004c, 0x080f, PHY_SAVE },
	{ 0x2004d, 0x0000, PHY_SAVE },
	{ 0x20041, 0x0001, PHY_SAVE },
	{ 0x90802, 0x0001, PHY_SAVE },
	{ 0x20045, 0x0002, PHY_SAVE },
};
static const struct phy_op phy_post_main_3[] = {
	{ 0x10057, 0x0000, PHY_SAVE },
};
static const struct phy_op phy_post_main_4[] = {
	{ 0x1000f, F_POST_1000F, PHY_VAR|PHY_SAVE },
};
static const struct phy_op phy_post_main_5[] = {
	{ 0x90803, 0x0004, PHY_SAVE },
	{ 0x90804, 0x0082, PHY_SAVE },
	{ 0x90805, 0x0001, PHY_SAVE },
	{ 0x90903, 0x0000, PHY_SAVE },
	{ 0x9090b, 0x0002, PHY_SAVE },
	{ 0x90811, 0x0000, PHY_NZ|PHY_SAVE },
	{ 0x90812, 0xff00, PHY_NZ|PHY_SAVE },
	{ 0x20072, 0x0003, PHY_SAVE },
	{ 0x9080e, 0x0003, PHY_SAVE },
	{ 0x20073, 0x0003, PHY_SAVE },
	{ 0x9080f, 0x0003, PHY_SAVE },
	{ 0x2004a, F_POST_2004A, PHY_VAR|PHY_SAVE },
	{ 0x2004b, F_POST_2004A, PHY_VAR|PHY_SAVE },
	{ 0x2004c, F_POST_2004C, PHY_VAR|PHY_SAVE },
};

const struct phy_group phy_post_main[] = {
	{ phy_post_main_0, 1, PHY_LOOP_ONCE },
	{ phy_post_main_1, 2, PHY_LOOP_AC },
	{ phy_post_main_2, 5, PHY_LOOP_ONCE },
	{ phy_post_main_3, 1, PHY_LOOP_LANE },
	{ phy_post_main_4, 1, PHY_LOOP_LANE },
	{ phy_post_main_5, 14, PHY_LOOP_ONCE },
};
const unsigned int phy_post_main_count = 6;

static const struct phy_op phy_common_0[] = {
	{ 0x2004a, F_CFG_2004A, PHY_VAR },
	{ 0x2004b, 0x123e, 0 },
	{ 0x20088, 0x0101, 0 },
	{ 0x20060, 0x0002, 0 },
	{ 0x200a5, 0x0001, 0 },
	{ 0xd0036, 0x0000, 0 },
	{ 0x200bd, 0x00ff, 0 },
	{ 0x20300, 0x0808, 0 },
	{ 0x20303, 0x0009, 0 },
	{ 0x20302, 0x0026, 0 },
	{ 0x20328, 0x0000, 0 },
	{ 0x20301, 0x0003, 0 },
	{ 0x2030b, 0x0000, 0 },
};
static const struct phy_op phy_common_1[] = {
	{ 0x300ae, 0x0080, 0 },
	{ 0x300ad, 0x0080, 0 },
	{ 0x300ac, 0x0080, 0 },
};
static const struct phy_op phy_common_2[] = {
	{ 0xc0086, 0x0000, 0 },
	{ 0x100a3, 0x0b3f, 0 },
	{ 0x110a3, 0x0b33, 0 },
	{ 0x120a3, 0x0b3f, 0 },
	{ 0x130a3, 0x0b33, 0 },
	{ 0xc0121, 0x0002, 0 },
	{ 0xc00f1, 0x6000, 0 },
	{ 0xc00f2, 0x00a9, 0 },
	{ 0xc00f3, 0x8000, 0 },
	{ 0xc00f4, 0x5555, 0 },
	{ 0xc00f5, 0x4000, 0 },
	{ 0xc00f6, 0x2222, 0 },
	{ 0xc00f7, 0xf000, 0 },
	{ 0xc00f9, 0x6000, 0 },
	{ 0xc00fa, 0x00a9, 0 },
	{ 0xc00fb, 0x8000, 0 },
	{ 0xc00fc, 0x0000, 0 },
	{ 0xc00fd, 0x4000, 0 },
	{ 0xc00fe, 0x0000, 0 },
	{ 0xc00ff, 0xf000, 0 },
	{ 0x908ff, 0x000f, 0 },
};
static const struct phy_op phy_common_3[] = {
	{ 0x10093, 0x0000, 0 },
};
static const struct phy_op phy_common_4[] = {
	{ 0x20051, 0x0003, 0 },
};

const struct phy_group phy_common[] = {
	{ phy_common_0, 13, PHY_LOOP_ONCE },
	{ phy_common_1, 3, PHY_LOOP_AC },
	{ phy_common_2, 21, PHY_LOOP_ONCE },
	{ phy_common_3, 1, PHY_LOOP_LANE },
	{ phy_common_4, 1, PHY_LOOP_ONCE },
};
const unsigned int phy_common_count = 5;

