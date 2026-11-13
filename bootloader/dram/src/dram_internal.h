/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Internal definitions of the A733 DRAM initialisation library.
 */
#ifndef DRAM_INTERNAL_H
#define DRAM_INTERNAL_H

#include "a733_dram.h"
#include "dram_fields.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)	(sizeof(a) / sizeof((a)[0]))
#endif

/* Hardware blocks */
#define CCU_BASE	0x02002000u
#define SYS2_BASE	0x02020000u
#define SYSCFG_BASE	0x03000000u
#define PRCM_BASE	0x07010000u
#define GLUE_BASE	0x0a020000u
#define CTL_BASE(ch)	(0x0a100000u + (uint32_t)(ch) * 0x400000u)
#define PHY_BASE	0x0a900000u
#define DRAM_BASE	0x40000000u

#define CHANNELS	2
#define RANKS		2
#define BYTE_LANES	4
#define AC_GROUPS	2
#define LANE_BITS	9	/* eight data bits and one more per byte lane */
#define PSTATES		4
#define LANE_STRIDE	0x1000u
#define BIT_STRIDE	0x100u

/* CCU */
#define CCU_PLL_DDR	0x020
#define CCU_DRAM_CLK	0xc00
#define CCU_DRAM_BGR	0xc0c
#define CCU_DRAM_GATE0	0x580
#define CCU_DRAM_GATE1	0x584
#define CCU_DRAM_GATE2	0x588

/* Glue block around controller and PHY */
#define GLUE_CTRL	0x10
#define GLUE_MRR(ch)	((ch) ? 0x40u : 0x2cu)
#define GLUE_DFS_SCRIPT	0x1800
#define GLUE_DFS_PARAM	0x1d00

/* PRCM */
#define PRCM_PAD_HOLD	0x250

/* DesignWare DDR controller, global registers */
#define CTL_MSTR	0x10000
#define CTL_STAT	0x10014
#define CTL_MRCTRL0	0x10080
#define CTL_MRCTRL1	0x10084
#define CTL_MRSTAT	0x10090
#define CTL_PWRCTL	0x10180
#define CTL_DFIMISC	0x10510
#define CTL_DFISTAT	0x10514
#define CTL_RETRAIN	0x10b84
#define CTL_RETRAIN_ST	0x10b88
#define CTL_SWCTL	0x10c80
#define CTL_SWSTAT	0x10c84
#define CTL_RFSH	0x10d00
/* Per-Pstate register sets, 0x100000 apart */
#define CTL_PSTATE(p)	((uint32_t)(p) * 0x100000u)

/* DesignWare LPDDR5 PHY, addresses in PHY register units */
#define PHY_IMEM	0x50000
#define PHY_DMEM	0x58000
#define PHY_DMEM_END	0x60000
#define PHY_SEQ_PSTATE	0xc0080
#define PHY_MUX		0xd0000
#define PHY_MAILBOX_ST	0xd0004
#define PHY_MSG_ACK	0xd0031
#define PHY_MSG_LO	0xd0032
#define PHY_MSG_ACK2	0xd0033
#define PHY_MSG_HI	0xd0034
#define PHY_FW_CTRL	0xd0099
#define PHY_TRAIN_DONE	0x07

/* Save list in the PHY's sequence memory, one area per Pstate */
#define PHY_SAVE_AREA(p)	(0xa0000u + (uint32_t)(p) * 0x1000u)
#define PHY_SAVE_SEQ		0x000	/* copy of the sequence table */
#define PHY_SAVE_HEAD		0x398	/* ten records of clock settings */
#define PHY_SAVE_HEAD_POST	0x3ac	/* the five filled in after training */
#define PHY_SAVE_HEAD_LAST	0x3bc
#define PHY_SAVE_MAIN		0x3c0	/* everything else */
#define PHY_SAVE_HEAD_RECORDS	10

/* Offsets into the firmware payload */
#define PAYLOAD_MSG_A		0x0cb28	/* 9 words of the message block */
#define PAYLOAD_MSG_B		0x0cebb	/* 13 words, Pstates 1 to 3 */
#define PAYLOAD_MSG_C		0x0ce23	/* 16 words */
#define PAYLOAD_MSG_D		0x1efe9	/* 9 words */
#define PAYLOAD_LP5_DMEM	0x0e40a
#define PAYLOAD_LP5_DMEM_WORDS	666
#define PAYLOAD_SEQ_A		0x20646	/* sequence table at PHY 0x41388 */
#define PAYLOAD_SEQ_A_WORDS	2256
#define PAYLOAD_SEQ_B		0x1e3de	/* sequence table at PHY 0x9002e */
#define PAYLOAD_SEQ_B_WORDS	1290
#define PAYLOAD_LP5_IMEM	0x0e93e
#define PAYLOAD_LP5_IMEM_WORDS	32080

/* Parameter block fields */
#define PARA_TYPE_LPDDR5	9
#define TPR13_SKIP_SCAN		(1u << 0)
#define TPR13_FOUR_PSTATES	(1u << 2)
#define TPR13_DUAL_CHANNEL	(1u << 6)
#define TPR13_THREE_QUARTER	(7u << 16)
#define TPR13_LOW_POWER		(1u << 24)

/* One PHY register write of a table. */
struct phy_op {
	uint32_t addr;
	uint16_t val;	/* value, or index into dram_freq_cfg.phy[] */
	uint8_t flags;
};

#define PHY_SAVE	0x01	/* also record the write in the save list */
#define PHY_VAR		0x02	/* val is a field of the frequency row */
#define PHY_QFREQ	0x04	/* value is the Pstate frequency / 4 */
#define PHY_NZ		0x08	/* val, plus 1 on every Pstate but 0 */

enum phy_loop {
	PHY_LOOP_ONCE,
	PHY_LOOP_LANE,		/* once per byte lane */
	PHY_LOOP_AC,		/* once per command/address group */
	PHY_LOOP_LANE_BIT,	/* once per bit of each byte lane */
};

struct phy_group {
	const struct phy_op *ops;
	uint16_t count;
	uint8_t loop;
};

enum phy_step_type {
	PHY_STEP_ONCE = PHY_LOOP_ONCE,
	PHY_STEP_LANE = PHY_LOOP_LANE,
	PHY_STEP_AC = PHY_LOOP_AC,
	PHY_STEP_LANE_BIT = PHY_LOOP_LANE_BIT,
	PHY_STEP_DATA,		/* consecutive registers from an array */
	PHY_STEP_FILL,		/* consecutive registers, one value */
	PHY_STEP_PAYLOAD,	/* consecutive registers from the payload */
};

struct phy_step {
	uint8_t type;
	uint32_t addr;
	uint16_t count;
	uint16_t val;
	const uint16_t *data;
	const struct phy_op *ops;
	uint32_t offset;	/* into the payload */
};

/* One register of the controller's per-Pstate timing set. */
struct ctl_timing_op {
	uint16_t off;
	uint32_t mask;	/* 0: plain write; else the field to replace */
	uint32_t val;
	uint8_t var;	/* FC_NONE, or index into dram_freq_cfg.ctl[] */
};

#define FC_NONE	0xff

struct dfs_word {
	uint16_t off;	/* offset in the glue block */
	uint32_t val;
};

struct dfs_segment {
	const struct dfs_word *words;
	uint16_t count;
};

#define DFS_SEGMENTS	5

/* Everything that is chosen by the frequency of a Pstate. */
struct dram_freq_cfg {
	uint16_t mhz;
	uint32_t ctl_rfsh;	/* only for frequencies used as Pstate 0 */
	uint32_t ctl[FC_COUNT];
	uint16_t phy[F_COUNT];
};

extern const struct dram_freq_cfg dram_freq_table[];
extern const unsigned int dram_freq_table_count;
extern const struct ctl_timing_op ctl_timing_ops[];
extern const unsigned int ctl_timing_op_count;
extern const struct dfs_segment dfs_segments[DFS_SEGMENTS];

extern const struct phy_group phy_common[];
extern const unsigned int phy_common_count;
extern const struct phy_group phy_cfg_head[];
extern const unsigned int phy_cfg_head_count;
extern const struct phy_group phy_cfg_main[];
extern const unsigned int phy_cfg_main_count;
extern const struct phy_group phy_post_head[];
extern const unsigned int phy_post_head_count;
extern const struct phy_group phy_post_seq[];
extern const unsigned int phy_post_seq_count;
extern const struct phy_group phy_post_main[];
extern const unsigned int phy_post_main_count;
extern const struct phy_step phy_final_steps[];
extern const unsigned int phy_final_step_count;

/* A register write waiting for its neighbour before it goes to the save list */
struct phy_save {
	uint32_t ptr;		/* PHY address of the next record */
	uint32_t addr;		/* even address of the pending pair */
	uint16_t val[2];
	uint8_t valid;		/* SAVE_EVEN, SAVE_ODD */
};

struct dram {
	const struct a733_dram_ops *ops;
	struct a733_dram_para *para;
	const uint8_t *payload;
	size_t payload_len;
	unsigned int pstates;			/* number trained */
	uint8_t divider[PSTATES];
	uint16_t mhz[PSTATES];
	const struct dram_freq_cfg *freq[PSTATES];
	struct phy_save save;
	uint32_t save_main[PSTATES];		/* end of the main save list */
	int err;
};

/* dram_io.c */
uint32_t rd32(struct dram *d, uint32_t addr);
void wr32(struct dram *d, uint32_t addr, uint32_t val);
void rmw32(struct dram *d, uint32_t addr, uint32_t clear, uint32_t set);
void setbits32(struct dram *d, uint32_t addr, uint32_t set);
void clrbits32(struct dram *d, uint32_t addr, uint32_t clear);
void wait32(struct dram *d, uint32_t addr, uint32_t mask, uint32_t match);
void dram_udelay(struct dram *d, uint32_t usec);
void dram_log(struct dram *d, const char *text, uint32_t value);
void dram_fail(struct dram *d, const char *text, uint32_t value);
uint16_t phy_rd(struct dram *d, uint32_t reg);
void phy_wr(struct dram *d, uint32_t reg, uint16_t val);
void phy_wait(struct dram *d, uint32_t reg, uint16_t mask, uint16_t match);
void phy_fill(struct dram *d, uint32_t reg, uint32_t count, uint16_t val);
void phy_load(struct dram *d, uint32_t reg, uint32_t count, uint32_t offset);

/* dram_para.c */
int dram_para_check(struct dram *d);
uint32_t dram_para_size_mib(const struct a733_dram_para *para);

/* dram_clock.c */
int dram_power(struct dram *d);
void dram_clocks_init(struct dram *d);
void dram_glue_release_resets(struct dram *d);
void dram_clock_set_pstate(struct dram *d, unsigned int pstate);

/* dram_ctl.c */
void ctl_sw_open(struct dram *d, unsigned int ch);
void ctl_sw_close(struct dram *d, unsigned int ch);
void ctl_sw_close_wait(struct dram *d, unsigned int ch);
void ctl_init(struct dram *d, unsigned int ch);
void ctl_select_pstate(struct dram *d, unsigned int pstate);
void ctl_adjust_timing(struct dram *d, unsigned int ch);
void ctl_handover(struct dram *d);
void ctl_remap(struct dram *d);
void ctl_dfs_setup(struct dram *d);
void ctl_mr_write(struct dram *d, unsigned int ch, unsigned int reg,
		  unsigned int val);
unsigned int ctl_mr_read(struct dram *d, unsigned int ch, unsigned int rank,
			 unsigned int reg);

/* dram_phy.c */
void phy_save_seek(struct dram *d, uint32_t ptr);
void phy_save_flush(struct dram *d);
void phy_save_record(struct dram *d, uint32_t addr, uint16_t even,
		     uint16_t odd, unsigned int valid);
void phy_wr_saved(struct dram *d, uint32_t reg, uint16_t val);
void phy_run_groups(struct dram *d, const struct phy_group *groups,
		    unsigned int count, unsigned int pstate);
void phy_run_steps(struct dram *d, const struct phy_step *steps,
		   unsigned int count, unsigned int pstate);
void phy_init_common(struct dram *d);
void phy_load_firmware(struct dram *d);
void phy_config_pstate(struct dram *d, unsigned int pstate);
void phy_finish(struct dram *d);

/* dram_train.c */
void phy_write_msg_block(struct dram *d, unsigned int pstate);
void phy_write_swap(struct dram *d);
int phy_run_firmware(struct dram *d, unsigned int pstate);
void phy_post_train(struct dram *d, unsigned int pstate);
void phy_read_back(struct dram *d);

#endif /* DRAM_INTERNAL_H */
