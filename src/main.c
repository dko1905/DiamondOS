/*-
 * SPDX-License-Identifier: CC0-1.0
 *
 * From https://github.com/limine-bootloader/limine-barebones/
 */
#include <stivale2.h>

#include <kern/types.h>
#include <kern/init/init.h>
#include <kern/init/gdt.h>

static uint8_t stack[4096] = {0};
void _start(struct stivale2_struct *info);

struct stivale2_header_tag_smp smp_request = {
    .tag = {
        .identifier = STIVALE2_HEADER_TAG_SMP_ID,
        .next       = 0
    },
    .flags = 0
};

__attribute__((section(".stivale2hdr"), used))
struct stivale2_header header2 = {
    .entry_point = (uint64_t)_start,
    .stack       = (uintptr_t)stack + sizeof(stack),
    .flags       = 0,
    .tags        = (uint64_t)&smp_request
};

void _start(struct stivale2_struct *info) {
	kern_init_gdt_init();
    kmain();
}
