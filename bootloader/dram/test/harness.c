// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Host harness for the A733 DRAM library: the reference model of
 * docs/dram-init-spec.md.
 *
 *  - every register starts at 0 and reads back the last value written;
 *  - a poll ends at once;
 *  - PHY 0xd0032 reads 0x07 and 0xd0034 reads 0 (training succeeded).
 *
 * Prints one line per event:
 *   W <address hex> <size> <value hex>   register write
 *   D <microseconds>                     delay
 *   P <rail> <mV>                        PMIC rail
 *   R <MiB>                              return value
 * Accesses to DRAM itself (the memory test) are served but not printed.
 *
 * usage: harness <boot0 file> <strap index> [packed]
 *
 * With "packed" the library gets only the ranges of the payload it reads,
 * as an SPL does, instead of the whole payload.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a733_dram.h"

/* Where the payload sits in boot0, from the specification. */
#define PAYLOAD_OFFSET	0x196b0
#define PAYLOAD_END	0x3ae98

#define PHY_MSG_LO	(0x0a900000u + (0xd0032u << 1))
#define PHY_MSG_HI	(0x0a900000u + (0xd0034u << 1))
#define DRAM_BASE	0x40000000u

#define SLOTS		(1u << 20)

struct slot {
	uint32_t addr;
	uint32_t val;
	int used;
};

static struct slot *regs;
static unsigned int strap_index;

static struct slot *lookup(uint64_t addr)
{
	uint32_t i = (uint32_t)((addr * 0x9e3779b97f4a7c15ull) >> 44) % SLOTS;

	while (regs[i].used && regs[i].addr != addr)
		i = (i + 1) % SLOTS;

	return &regs[i];
}

static uint32_t reg_read(uint32_t addr)
{
	struct slot *s = lookup(addr);

	if (addr == PHY_MSG_LO)
		return 0x07;
	if (addr == PHY_MSG_HI)
		return 0;

	return s->used ? s->val : 0;
}

static void reg_write(uint32_t addr, unsigned int size, uint32_t val)
{
	struct slot *s = lookup(addr);

	s->addr = addr;
	s->val = val;
	s->used = 1;

	if (addr < DRAM_BASE)
		printf("W %08x %u %x\n", addr, size, val);
}

static uint32_t h_read32(void *ctx, uint32_t addr)
{
	(void)ctx;
	return reg_read(addr);
}

static void h_write32(void *ctx, uint32_t addr, uint32_t val)
{
	(void)ctx;
	reg_write(addr, 4, val);
}

static uint16_t h_read16(void *ctx, uint32_t addr)
{
	(void)ctx;
	return (uint16_t)reg_read(addr);
}

static void h_write16(void *ctx, uint32_t addr, uint16_t val)
{
	(void)ctx;
	reg_write(addr, 2, val);
}

static int h_wait(void *ctx, uint32_t addr, unsigned int width, uint32_t mask,
		  uint32_t match)
{
	(void)ctx;
	(void)addr;
	(void)width;
	(void)mask;
	(void)match;
	return 0;
}

static void h_udelay(void *ctx, uint32_t usec)
{
	(void)ctx;
	printf("D %u\n", usec);
}

static int h_pmic_set(void *ctx, enum a733_dram_rail rail, unsigned int mv)
{
	static const char *const names[] = {
		[A733_DRAM_RAIL_DCDC6] = "dcdc6",
		[A733_DRAM_RAIL_DCDC7] = "dcdc7",
		[A733_DRAM_RAIL_DCDC8] = "dcdc8",
		[A733_DRAM_RAIL_ELDO1] = "eldo1",
		[A733_DRAM_RAIL_ELDO2] = "eldo2",
	};

	(void)ctx;
	printf("P %s %u\n", names[rail], mv);
	return 0;
}

static void h_log(void *ctx, const char *text, uint32_t value)
{
	(void)ctx;
	fprintf(stderr, "%s %u (0x%x)\n", text, value, value);
}

static unsigned int h_strap(void *ctx)
{
	(void)ctx;
	return strap_index;
}

static const struct a733_dram_ops ops = {
	.read32 = h_read32,
	.write32 = h_write32,
	.read16 = h_read16,
	.write16 = h_write16,
	.wait = h_wait,
	.udelay = h_udelay,
	.pmic_set = h_pmic_set,
	.log = h_log,
	.strap = h_strap,
};

int main(int argc, char **argv)
{
	static uint8_t payload[PAYLOAD_END - PAYLOAD_OFFSET];
	struct a733_dram_para para;
	uint32_t mib;
	FILE *f;

	if (argc != 3 && !(argc == 4 && !strcmp(argv[3], "packed"))) {
		fprintf(stderr, "usage: %s <boot0 file> <strap index> [packed]\n",
			argv[0]);
		return 2;
	}

	f = fopen(argv[1], "rb");
	if (!f || fseek(f, PAYLOAD_OFFSET, SEEK_SET) ||
	    fread(payload, 1, sizeof(payload), f) != sizeof(payload)) {
		fprintf(stderr, "%s: cannot read the payload\n", argv[1]);
		return 2;
	}
	fclose(f);

	strap_index = (unsigned int)strtoul(argv[2], NULL, 0);
	regs = calloc(SLOTS, sizeof(*regs));
	if (!regs)
		return 2;

	if (argc == 4) {
		static uint8_t packed[sizeof(payload)];
		size_t len = 0;
		unsigned int i;

		for (i = 0; i < a733_dram_payload_range_count; i++) {
			const struct a733_dram_payload_range *r =
				&a733_dram_payload_ranges[i];

			memcpy(packed + len, payload + r->offset, r->len);
			len += r->len;
		}
		mib = a733_dram_init(&ops, packed, len, &para);
	} else {
		mib = a733_dram_init(&ops, payload, sizeof(payload), &para);
	}
	printf("R %u\n", mib);
	fprintf(stderr, "para1 = %x, para2 = %x, tpr13 = %x\n",
		para.word[A733_DRAM_PARA1], para.word[A733_DRAM_PARA2],
		para.word[A733_DRAM_TPR13]);

	return mib ? 0 : 1;
}
