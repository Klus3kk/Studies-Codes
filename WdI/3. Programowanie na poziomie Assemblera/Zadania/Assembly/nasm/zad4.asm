%include "AuxMacros.asm"
section .text
global _start
_start: ; NWD(ax,bx)
 mov ax, 18 ; first argument
 mov bx, 18 ; second argument
 mov cx, 0
whi: cmp ax, bx
 je kon
 cmp ax, cx
 je kon
 cmp bx, cx
 je zer
 jle els
 sub ax, bx
 jmp od
els: sub bx, ax
od: jmp whi
zer: 
 mov ax, 0
 jmp kon
kon:
 printReg ax ; printf(("%h\n", ax);
 return0 ; return 0;
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg
