%include "AuxMacros.asm"
section .text
global _start
_start:
 mov ax, sp
 mov bx, 1
 push bx
 sub ax, sp
 printReg ax
 return0
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg 
