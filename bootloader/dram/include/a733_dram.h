/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * DRAM initialisation for the Allwinner A733 (LPDDR5, two channels).
 *
 * The library is freestanding: it reaches the hardware only through the
 * callbacks in struct a733_dram_ops and takes the PHY firmware payload as a
 * pointer and a length. See README.md.
 */
#ifndef A733_DRAM_H
#define A733_DRAM_H

#include <stddef.h>
#include <stdint.h>

/* PMIC rails the DRAM supplies are on. */
enum a733_dram_rail {
	A733_DRAM_RAIL_DCDC6,
	A733_DRAM_RAIL_DCDC7,
	A733_DRAM_RAIL_DCDC8,
	A733_DRAM_RAIL_ELDO1,
	A733_DRAM_RAIL_ELDO2,
};

/*
 * Platform interface. Addresses are physical addresses. The 32-bit read and
 * write are also used for the memory test at the end, on DRAM itself.
 */
struct a733_dram_ops {
	uint32_t (*read32)(void *ctx, uint32_t addr);
	void (*write32)(void *ctx, uint32_t addr, uint32_t val);
	uint16_t (*read16)(void *ctx, uint32_t addr);
	void (*write16)(void *ctx, uint32_t addr, uint16_t val);
	/*
	 * Poll the register of the given width (16 or 32 bits) until
	 * (value & mask) == match. Returns 0, or non-zero on timeout.
	 */
	int (*wait)(void *ctx, uint32_t addr, unsigned int width,
		    uint32_t mask, uint32_t match);
	void (*udelay)(void *ctx, uint32_t usec);
	/* Returns 0, or non-zero if the rail could not be set. */
	int (*pmic_set)(void *ctx, enum a733_dram_rail rail, unsigned int mv);
	/* One line of text followed by one number. */
	void (*log)(void *ctx, const char *text, uint32_t value);
	/* Index read from the board's memory strap. */
	unsigned int (*strap)(void *ctx);
	void *ctx;
};

/* The firmware payload: the block the specification calls "payload". */
#define A733_DRAM_PAYLOAD_SIZE	137192u

/* Words of the parameter block, see docs/dram-init-spec.md. */
#define A733_DRAM_PARA_WORDS	52

enum {
	A733_DRAM_CLK = 0,	/* MHz */
	A733_DRAM_TYPE = 1,	/* 8 LPDDR4, 9 LPDDR5 */
	A733_DRAM_PARA1 = 6,	/* address geometry */
	A733_DRAM_PARA2 = 7,	/* ranks; size in MiB in the upper half */
	A733_DRAM_TPR13 = 30,	/* feature flags */
	A733_DRAM_TRAINED = 32,	/* first word of the read-back area */
	A733_DRAM_MR14 = 50,
	A733_DRAM_MR15 = 51,
};

struct a733_dram_para {
	uint32_t word[A733_DRAM_PARA_WORDS];
};

/*
 * Copy the parameter block that belongs to a strap index of the
 * Orange Pi Zero 3W. Unknown indices give the default block.
 */
void a733_dram_select_para(unsigned int strap, struct a733_dram_para *para);

/*
 * Initialise DRAM with the given parameter block. The block is updated with
 * the size and the values read back after training.
 * Returns the size in MiB, or 0 on failure.
 */
uint32_t a733_dram_init_para(const struct a733_dram_ops *ops,
			     const uint8_t *payload, size_t payload_len,
			     struct a733_dram_para *para);

/*
 * Read the strap, select the parameter block and initialise DRAM. If para is
 * not NULL it receives the block that was used, for the next boot stage.
 * Returns the size in MiB, or 0 on failure.
 */
uint32_t a733_dram_init(const struct a733_dram_ops *ops,
			const uint8_t *payload, size_t payload_len,
			struct a733_dram_para *para);

#endif /* A733_DRAM_H */
