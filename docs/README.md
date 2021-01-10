# ![Diamond OS](./logo/wide_logo.png)

## Progress
- [x] Boot the kernel.
- [ ] Setup GDT.

## Compiling and running
You will need a compiler, a linker and make installed to compile the kernel.
To compile the kernel, run `make`. To run the kernel you need to create a
bootable image. The makefile can automatically do it, if you run the disk.hdd
target, `make disk.hdd`. The disk.hdd target requires parted and
[echfs-utils](https://github.com/echfs/echfs) installed. The makefile also
has a run target, that starts QEMU with the image, you need to have a QEMU
install to have it work.

## License
[BSD-2-Clause](./LICENSE).
