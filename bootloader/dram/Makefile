# SPDX-License-Identifier: GPL-2.0-or-later
#
# Host build and test of the A733 DRAM library.
#
#   make            build the library (build/libdram.a)
#   make check      run the four memory fits against the reference scripts
#
# CROSS_COMPILE=aarch64-linux-gnu- make lib   builds the library only.

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar
PYTHON	?= python3

CFLAGS	?= -O2
WARN	= -std=c11 -Wall -Wextra -Werror
FREE	= -ffreestanding -fno-builtin

TOP	= ../..
DOCS	= $(TOP)/docs/dram-init
BOOT0	?= $(TOP)/vendor/blobs/orangepi-build/external/packages/pack-uboot/sun60iw2/bin/boot0_sdcard_orangepizero3w.fex

SRCS	= $(sort $(wildcard src/*.c))
OBJS	= $(SRCS:src/%.c=build/%.o)

# memory fit:strap index
FITS	= 4g:0 6g:1 8g:2 12g:5

all: lib

lib: build/libdram.a

build/%.o: src/%.c $(wildcard src/*.h) include/a733_dram.h
	@mkdir -p build
	$(CC) $(WARN) $(FREE) $(CFLAGS) -Iinclude -Isrc -c -o $@ $<

build/libdram.a: $(OBJS)
	$(AR) rcs $@ $^

build/harness: test/harness.c build/libdram.a
	$(CC) $(WARN) $(CFLAGS) -Iinclude -o $@ $< build/libdram.a

# Packs the ranges of the payload the library reads into one file, for an SPL.
build/payload-pack: tools/payload-pack.c build/libdram.a
	$(CC) $(WARN) $(CFLAGS) -Iinclude -o $@ $< build/libdram.a

tools: build/payload-pack

check: build/harness
	@for fit in $(FITS); do \
		name=$${fit%%:*}; strap=$${fit##*:}; \
		build/harness $(BOOT0) $$strap > build/run-$$name.txt 2> build/log-$$name.txt; \
		$(PYTHON) test/compare.py $(DOCS)/ops-$$name.tsv $(BOOT0) build/run-$$name.txt || exit 1; \
		build/harness $(BOOT0) $$strap packed 2> /dev/null | cmp -s - build/run-$$name.txt \
			|| { echo "FAIL $$name: packed payload gives a different run"; exit 1; }; \
	done
	@echo "PASS packed payload: same runs"
	@$(PYTHON) test/check_payload.py $(BOOT0) build/libdram.a src include test tools Makefile README.md

clean:
	$(RM) -r build

.PHONY: all lib tools check clean
