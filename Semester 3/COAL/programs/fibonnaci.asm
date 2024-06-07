[org 0x0100]

jmp start
arr: dw 0,0,0,0,0,0,0,0,0,0

start:
mov bx, arr
mov ax, [bx]
add bx, 2
mov word[bx], 1
mov cx, 8
repeat:
add ax, [bx]
add bx, 2
mov [bx], ax
mov ax, [bx - 2]
sub cx, 1
jnz repeat

mov ax, 0x4c00
int 0x21