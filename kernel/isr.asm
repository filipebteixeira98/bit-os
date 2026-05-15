[bits 32]

global isr1

isr1:
  cli

  pusha

  call keyboard_handler

  popa

  sti

  iret
