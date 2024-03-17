%include "AuxMacros.asm"
section .text
global _start
_start:
 ; ax = min(bx,cx)
 mov bx,7 ; first argument
 mov cx,8 ; second argument
 mov ax, bx
 cmp ax, cx
 jle ok
 mov ax, cx
ok:
 printReg ax ; printf("%h\n", ax);
 return0 ; return 0;
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg
