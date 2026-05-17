#include "screen.h"
#include "idt.h"
#include "pic.h"
#include "shell.h"

extern void isr1();

void kernel_main() {
  clear_screen();

  pic_remap();

  set_idt_gate(0x21, (unsigned)isr1);

  set_idt();

  __asm__ volatile("sti");

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  shell_init();

  while(1);
}
