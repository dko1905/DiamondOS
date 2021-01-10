.POSIX:

include config.mk

all: options src/diamond.elf

options:
	@echo Diamond OS build options:
	@echo "CFLAGS  = $(MYCFLAGS)"
	@echo "LDFLAGS = $(MYLDFLAGS)"
	@echo "CC      = $(CC)"
	@echo "LD      = $(LD)"

src/diamond.elf:
	$(MAKE) -C src CONFIG_MK="`pwd`/config.mk" \
	        INC="-I `pwd`/include -I `pwd`/limine/stivale/" \
	        all

# Compile limine bootloader install script.
limine/limine-install:
	$(MAKE) -C limine
# Create disk image with kernel and limine.
disk.hdd: src/diamond.elf limine/limine-install
	rm -f disk.hdd
	dd if=/dev/zero bs=1M count=0 seek=64 of=disk.hdd
	parted -s disk.hdd mklabel gpt
	parted -s disk.hdd mkpart primary 2048s 100%
	echfs-utils -g -p0 disk.hdd quick-format 512
	echfs-utils -g -p0 disk.hdd import src/diamond.elf diamond.elf
	echfs-utils -g -p0 disk.hdd import limine.cfg limine.cfg
	limine/limine-install disk.hdd

# Run limine disk image.
run: disk.hdd
	qemu-system-x86_64 -m 2G -drive file=file,index=0,format=raw,file=disk.hdd

clean:
	rm -f disk.hdd
	$(MAKE) -C src CONFIG_MK="`pwd`/config.mk" \
	        INC="-I `pwd`/include -I `pwd`/limine/stivale/" \
	        clean
	$(MAKE) -C limine clean

.PHONY: all options src/diamond.elf run clean
