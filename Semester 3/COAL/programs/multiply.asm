[org 0x0100]

jmp start
result: dw 0

start:
mov ax, 20	;multiplier
mov bx, 2	;multiplicand
mov cx, 4	;number of bits in multiplier

repeat:
shr ax, 1	;shift the multiplier right
jnc skip 	;if carry is 1 add multiplicand to result

add [result], bx

skip:		;if carry is not 1, shift multiplicand left
shl bx, 1
sub cx, 1
jnz repeat	;repeat till the number of bits of multiplier

mov ax, 0x4c00
int 0x21