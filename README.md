# PauyOS Reimagined
A complete rewrite of PauyOS, now with docker!

## Usage
to run the operating system:
```bash
sudo docker run --rm -it -v "$(pwd)":/root/env pauyos-buildev;sudo qemu-system-x86_64 dist/x86_64/kernel.iso
```
```bash
make build-x86_64;exit
```