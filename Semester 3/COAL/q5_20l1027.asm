[org 0x0100]

start:
mov ax, [num]
mov dx, [num]
shl ax, 2
mov [m], ax
sar dx, 1
mov [d], dx

mov ax, 0x4c00
int 0x21

num: dw 24
m: dw 0
d: dw 0