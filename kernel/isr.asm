[bits 32]

global isr0
global isr1

extern timer_handler
extern keyboard_handler

isr0:
  pusha

  call timer_handler

  popa

  iret

isr1:
  pusha

  call keyboard_handler

  popa

  iret
