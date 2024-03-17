%include "AuxMacros.asm"
section .text
global _start
_start:
 mov ax, 3
 mov bx, 6
 push ax
 push bx
 pop ax
 pop bx
 printReg ax
 return0
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg 
