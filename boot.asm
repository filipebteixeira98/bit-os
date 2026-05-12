[org 0x7c00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

call load_kernel
call switch_to_pm

jmp $

BOOT_DRIVE db 0

load_kernel:
  mov bx, KERNEL_OFFSET
  mov dh, 15

  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov cl, 0x02
  mov dh, 0x00
  mov dl, [BOOT_DRIVE]

  int 0x13

  ret
