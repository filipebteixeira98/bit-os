[org 0x7c00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

call load_kernel
call switch_to_pm

jmp $

BOOT_DRIVE db 0
