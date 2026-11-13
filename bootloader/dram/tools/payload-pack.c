// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Cut the parts of the PHY firmware payload that the A733 DRAM library
 * reads out of a boot0 file and write them as one packed payload.
 *
 * usage: payload-pack <boot0 file> <output> [zero]
 *
 * With "zero" the output has the same size and holds zeros only: a stand-in
 * for builds whose result is published.
 *
 * The output holds firmware without a redistribution grant. Do not commit
 * or publish it.
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "a733_dram.h"

/* Where the payload sits in boot0, from docs/dram-init-spec.md. */
#define PAYLOAD_OFFSET	0x196b0

int main(int argc, char **argv)
{
	static uint8_t payload[A733_DRAM_PAYLOAD_SIZE];
	int zero = argc == 4 && !strcmp(argv[3], "zero");
	size_t total = 0;
	unsigned int i;
	FILE *f;

	if (argc != 3 && !zero) {
		fprintf(stderr, "usage: %s <boot0 file> <output> [zero]\n",
			argv[0]);
		return 2;
	}

	if (!zero) {
		f = fopen(argv[1], "rb");
		if (!f || fseek(f, PAYLOAD_OFFSET, SEEK_SET) ||
		    fread(payload, 1, sizeof(payload), f) != sizeof(payload)) {
			fprintf(stderr, "%s: cannot read the payload\n",
				argv[1]);
			return 1;
		}
		fclose(f);
	}

	f = fopen(argv[2], "wb");
	if (!f) {
		fprintf(stderr, "%s: cannot create\n", argv[2]);
		return 1;
	}

	for (i = 0; i < a733_dram_payload_range_count; i++) {
		const struct a733_dram_payload_range *r =
			&a733_dram_payload_ranges[i];

		if (fwrite(payload + r->offset, 1, r->len, f) != r->len) {
			fprintf(stderr, "%s: write failed\n", argv[2]);
			return 1;
		}
		total += r->len;
	}

	if (fclose(f) || total != a733_dram_payload_packed_size()) {
		fprintf(stderr, "%s: write failed\n", argv[2]);
		return 1;
	}

	printf("%s: %zu bytes in %u ranges\n", argv[2], total,
	       a733_dram_payload_range_count);
	return 0;
}
