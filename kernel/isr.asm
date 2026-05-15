[bits 32]

global isr1

extern keyboard_handler

isr1:
  cli

  pusha

  call keyboard_handler

  popa

  iret
