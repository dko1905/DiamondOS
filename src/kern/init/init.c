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

#include "kern/init/init.h"

#define VGA_ADDRESS 0xb8000
#define VGA_COLOR(character, color) ((uint16_t) (character) | (uint16_t) (color) << 8)
#define VGA_BLACK        0
#define VGA_BLUE         1
#define VGA_GREEN        2
#define VGA_CYAN         3
#define VGA_RED          4
#define VGA_PURPLE       5
#define VGA_BROWN        6
#define VGA_GRAY         7
#define VGA_DARK_GRAY    8
#define VGA_LIGHT_BLUE   9
#define VGA_LIGHT_GREEN  10
#define VGA_LIGHT_CYAN   11
#define VGA_LIGHT_RED    12
#define VGA_LIGHT_PURPLE 13
#define VGA_YELLOW       14
#define VGA_WHITE        15

void kmain() {
	volatile uint16_t *p = (uint16_t *)VGA_ADDRESS;
	p[0] = VGA_COLOR('h', VGA_RED);
	p[1] = VGA_COLOR('i', VGA_BLUE);
	p[2] = VGA_COLOR('\n', VGA_BLUE);
	p[3] = VGA_COLOR('n', VGA_BLUE);
	p[4] = VGA_COLOR('o', VGA_BLUE);
	asm volatile ("hlt");
}
