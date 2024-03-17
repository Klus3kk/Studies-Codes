#!/bin/bash
nasm -f elf zad2.asm
ld -m elf_i386 -s -o zad2 zad2.o
./zad2
