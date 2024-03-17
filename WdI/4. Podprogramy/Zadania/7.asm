%include "AuxMacros.asm"
section .text
global _start
_leng: push dx ; tmp
 push si ; tmp
 push ax ; param n
 push bx ; param b
 mov cx, 1 ; L= 1
_loop: mov si, bx
 sub si, 1
 cmp ax, si
 jng _pool ; while n > b-1:
 mov dx, 0
 div bx ; n //= b
 add cx, 1 ; L += 1
 jmp _loop
_pool: pop bx ; param b
 pop ax ; param n
 pop si ; tmp
 pop dx ; tmp
 ret
_start:
 mov ax, 65
 mov bx, 10
 call _leng
 printReg cx
 mov bx, 8
 call _leng
 printReg cx
 return0
section .data
HexDig db '0', '1', '2', '3'
 db '4', '5', '6', '7'
 db '8', '9', 'A', 'B'
 db 'C', 'D', 'E', 'F'
msg db '12 = 0000', 0xa
len equ $ - msg 
