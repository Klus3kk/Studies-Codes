#!/bin/bash
nasm -f elf zad4.asm
ld -m elf_i386 -s -o zad4 zad4.o
./zad4
