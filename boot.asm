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

gdt_start:

gdt_null:
  dd 0x0
  dd 0x0

gdt_code:
  dw 0xffff
  dw 0x0000
  db 0x00
  db 10011010b
  db 11001111b
  db 0x00

gdt_data:
  dw 0xffff
  dw 0x0000
  db 0x00
  db 10010010b
  db 11001111b
  db 0x00

gdt_end:

gdt_descriptor:
  dw gdt_end - gdt_start - 1
  dd gdt_start
