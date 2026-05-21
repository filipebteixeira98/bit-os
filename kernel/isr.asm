[bits 32]

global isr0
global isr1
global isr14

extern timer_handler
extern keyboard_handler
extern page_fault_handler

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

isr14:
  pusha

  call page_fault_handler

  popa

  add esp, 4

  iret
