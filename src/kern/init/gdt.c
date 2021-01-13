/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2021, Daniel Florescu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGE.
 */
#include <kern/types.h>
#include <kern/bits.h>

#include "kern/init/gdt.h"

struct kern_gdt_access {
	unsigned int accessed: 1;
	unsigned int readwrite: 1;
	unsigned int direction: 1;
	unsigned int execute: 1;
	unsigned int type: 1;
	unsigned int privilege: 2;
	unsigned int pr: 1;
} __attribute__((packed));

struct kern_gdt_descriptor {
	uint16_t low_limit: 16;
	uint16_t low_base: 16;
	unsigned int mid_base: 8;
	struct kern_gdt_access access; /* 8 */
	unsigned int mid_limit: 4;
	unsigned int flag_long: 1;
	unsigned int flag_zero: 2; /* As far as I know, they are unused. */
	unsigned int flag_size: 1;
	unsigned int flag_granularity: 1;
} __attribute__((packed));

struct kern_gdt_pointer {
	uint16_t size; /* Size of descriptor, size - 1. */
	uint64_t offset; /* Offset from 0x0. */
} __attribute__((packed));

struct kern_gdt_descriptor descriptions[3];
struct kern_gdt_pointer gdtr[3] = {};

void kern_init_gdt_init() {
	/* NULL pointer. */
	descriptions[0] = (struct kern_gdt_descriptor){
		.access = (struct kern_gdt_access){
			.pr = 1, /* Always needs to be 1. */
			.privilege = 0, /* Ring 0 memory. */
			.type = 1, /* This memory contains code or data. */
			.execute = 0, /* Don't allow execution. */
			.direction = 1, /* Grow down, since it's stack. */
			.readwrite = 1, /* Allow write since it's a data sector. */
			.accessed = 0,
		},
		.flag_long = 1, /* Must be 1 for 64 bit memory. */
		.flag_zero = 0,
		.flag_size = 0, /* Must be 0 when long is 1. */
		.flag_granularity = 0
	};
	gdtr[0] = (struct kern_gdt_pointer){
		.offset = (uint64_t)&descriptions[1],
		.size = sizeof(descriptions[1]) - 1
	};

	asm volatile(
		"lgdt %0"
		:
		: "m"(gdtr)
		: "memory"
	);
}
