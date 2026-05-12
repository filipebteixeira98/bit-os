[org 0x7c00]

mov ax, 0x0000
mov es, ax

mov bx, 0x1000
mov dh, 2

call load_kernel

jmp 0x0000:0x1000

load_kernel:
  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov cl, 0x02
  mov dh, 0x00
  mov dl, 0x80

  int 0x13

  jc disk_error
  
  ret

disk_error:
  mov ah, 0x0e
  mov al, 'E'
  int 0x10

  jmp $

times 510 - ($ - $$) db 0
dw 0xaa55
