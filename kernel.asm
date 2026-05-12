[org 0x1000]

mov ah, 0x0e

mov al, 'K'
int 0x10

mov al, 'E'
int 0x10

mov al, 'R'
int 0x10

mov al, 'N'
int 0x10

jmp $
