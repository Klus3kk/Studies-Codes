#!/bin/bash
nasm -f elf digits-total.asm
ld -m elf_i386 -s -o digits-total digits-total.o
./digits-total
