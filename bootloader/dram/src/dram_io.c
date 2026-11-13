// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Register access helpers on top of the platform interface.
 */

#include "dram_internal.h"

uint32_t rd32(struct dram *d, uint32_t addr)
{
	return d->ops->read32(d->ops->ctx, addr);
}

void wr32(struct dram *d, uint32_t addr, uint32_t val)
{
	d->ops->write32(d->ops->ctx, addr, val);
}

void rmw32(struct dram *d, uint32_t addr, uint32_t clear, uint32_t set)
{
	wr32(d, addr, (rd32(d, addr) & ~clear) | set);
}

void setbits32(struct dram *d, uint32_t addr, uint32_t set)
{
	rmw32(d, addr, 0, set);
}

void clrbits32(struct dram *d, uint32_t addr, uint32_t clear)
{
	rmw32(d, addr, clear, 0);
}

void dram_log(struct dram *d, const char *text, uint32_t value)
{
	if (d->ops->log)
		d->ops->log(d->ops->ctx, text, value);
}

/* Record the first failure; later steps still run but the init returns 0. */
void dram_fail(struct dram *d, const char *text, uint32_t value)
{
	if (!d->err)
		dram_log(d, text, value);
	d->err = 1;
}

void wait32(struct dram *d, uint32_t addr, uint32_t mask, uint32_t match)
{
	if (d->ops->wait(d->ops->ctx, addr, 32, mask, match))
		dram_fail(d, "DRAM: timeout waiting on register", addr);
}

void udelay(struct dram *d, uint32_t usec)
{
	d->ops->udelay(d->ops->ctx, usec);
}

/* PHY registers are 16 bits wide and two bytes apart. */
static uint32_t phy_addr(uint32_t reg)
{
	return PHY_BASE + (reg << 1);
}

uint16_t phy_rd(struct dram *d, uint32_t reg)
{
	return d->ops->read16(d->ops->ctx, phy_addr(reg));
}

void phy_wr(struct dram *d, uint32_t reg, uint16_t val)
{
	d->ops->write16(d->ops->ctx, phy_addr(reg), val);
}

void phy_wait(struct dram *d, uint32_t reg, uint16_t mask, uint16_t match)
{
	if (d->ops->wait(d->ops->ctx, phy_addr(reg), 16, mask, match))
		dram_fail(d, "DRAM: timeout waiting on PHY register", reg);
}

void phy_fill(struct dram *d, uint32_t reg, uint32_t count, uint16_t val)
{
	while (count--)
		phy_wr(d, reg++, val);
}

/* Every part of the payload the library reads, lowest offset first. */
const struct a733_dram_payload_range a733_dram_payload_ranges[] = {
	{ PAYLOAD_MSG_A, 2 * 9 },
	{ PAYLOAD_MSG_C, 2 * 16 },
	{ PAYLOAD_MSG_B, 2 * 13 },
	{ PAYLOAD_LP5_DMEM, 2 * PAYLOAD_LP5_DMEM_WORDS },
	{ PAYLOAD_LP5_IMEM, 2 * PAYLOAD_LP5_IMEM_WORDS },
	{ PAYLOAD_SEQ_B, 2 * PAYLOAD_SEQ_B_WORDS },
	{ PAYLOAD_MSG_D, 2 * 9 },
	{ PAYLOAD_SEQ_A, 2 * PAYLOAD_SEQ_A_WORDS },
};

const unsigned int a733_dram_payload_range_count =
	ARRAY_SIZE(a733_dram_payload_ranges);

size_t a733_dram_payload_packed_size(void)
{
	size_t size = 0;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(a733_dram_payload_ranges); i++)
		size += a733_dram_payload_ranges[i].len;

	return size;
}

/*
 * Where count words at an offset of the whole payload are in the payload
 * that was passed in, or NULL.
 */
static const uint8_t *payload_at(struct dram *d, uint32_t offset,
				 uint32_t count)
{
	size_t len = 2u * count;
	size_t pos = 0;
	unsigned int i;

	if (d->payload_len >= A733_DRAM_PAYLOAD_SIZE)
		return (size_t)offset + len <= d->payload_len ?
		       d->payload + offset : NULL;

	for (i = 0; i < ARRAY_SIZE(a733_dram_payload_ranges); i++) {
		const struct a733_dram_payload_range *r =
			&a733_dram_payload_ranges[i];

		if (offset >= r->offset &&
		    offset + len <= (size_t)r->offset + r->len)
			return d->payload + pos + (offset - r->offset);
		pos += r->len;
	}

	return NULL;
}

/* Copy little-endian 16-bit words from the firmware payload to the PHY. */
void phy_load(struct dram *d, uint32_t reg, uint32_t count, uint32_t offset)
{
	const uint8_t *p = payload_at(d, offset, count);

	if (!p) {
		dram_fail(d, "DRAM: firmware payload does not hold offset",
			  offset);
		return;
	}

	for (; count--; p += 2)
		phy_wr(d, reg++, (uint16_t)(p[0] | (p[1] << 8)));
}
