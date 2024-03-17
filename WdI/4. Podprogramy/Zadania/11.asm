%include "AuxMacros.asm"
section .text
global _start
fact: push dx ; tmp
 push ax ; param n
 cmp ax, 0
 jne fi ; if n==0:
 mov bx, 1
 pop ax ; param n
 pop dx ; tmp
 ret ; return 1
fi: push ax
 sub ax, 1
 call fact ; bx= fact(n-1)
 pop ax
 mul bx
 mov bx, ax; bx= n*bx
 pop ax ; param n
 pop dx ; tmp
 ret ; return bx
_start:
 mov ax, 4
 call fact
 printReg bx ; print(fact(4))
 return0
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg 
