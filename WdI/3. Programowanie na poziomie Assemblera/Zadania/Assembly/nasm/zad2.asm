%include "AuxMacros.asm"
section .text
global _start
_start:
 	   	; ax = 3 * ax;
 mov ax, -1 	; input data 
 mov bx, ax	; bx = ax
 add ax, ax 	; ax = ax + ax
 add ax, bx	; ax = ax + bx
 printReg ax 	; printf(("%h\n", ax);
 return0 	; return 0;
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg
