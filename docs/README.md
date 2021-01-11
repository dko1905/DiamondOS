# ![Diamond OS](./logo/wide_logo.png)

## Progress
- [x] Boot the kernel.
- [ ] Setup GDT.

## Compiling and running
You are required to have POSIX compliant make installed to build the kernel.<br/>
You are requited to have parted and [echfs-utils](https://github.com/echfs/echfs)
installed to create disk image.<br/>
And you need QEMU (x86-64) installed to run it.<br/>
Here are the steps to make it run:
1. Compile the kernel. `make`
2. Create bootable image. `make disk.hdd`
3. Run QEMU with image. `make run`

## License
[BSD-2-Clause](./license/LICENSE-bsd-2-clause.txt)
