# PauyOS Reimagined

A complete rewrite of PauyOS, now with docker!

> [!IMPORTANT]
> This has only been tested on linux systems, and you *will* need to modify the commands below for this to work on windows.

## Setup
```bash
sudo docker build buildenv -t pauyos-buildenv
```

## Usage
to run the operating system:
```bash
sudo docker run --rm -it -v "$(pwd)":/root/env pauyos-buildenv;sudo qemu-system-x86_64 -drive format=raw,file=dist/x86_64/kernel.iso
```
```bash
make build-x86_64;exit
```