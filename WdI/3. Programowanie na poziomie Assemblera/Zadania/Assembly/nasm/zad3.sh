#!/bin/bash
nasm -f elf zad3.asm
ld -m elf_i386 -s -o zad3 zad3.o
./zad3
