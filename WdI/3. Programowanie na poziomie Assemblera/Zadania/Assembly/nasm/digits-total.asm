%include "AuxMacros.asm"
section	.text
global _start
_start:
	mov ax, 34
	mov bx, 8
	mov cx, 0
_loop:
    cmp ax, bx
    jl _end
    push dx
    call _div_and_save
    pop dx
    jmp _loop
_div_and_save:
    mov dx, 0
    div bx
    add cx, dx
    ret
_end:
    add cx, ax
    printReg cx
	return0		;return 0;
section	.data
HexDig	db '0', '1', '2', '3'
	db '4', '5', '6', '7'
	db '8', '9', 'A', 'B'
	db 'C', 'D', 'E', 'F'
msg	db '12 = 0000', 0xa
len     equ $ - msg
