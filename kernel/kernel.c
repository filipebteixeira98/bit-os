#include "screen.h"
#include "idt.h"
#include "pic.h"
#include "shell.h"
#include "timer.h"

extern void isr0();
extern void isr1();

void kernel_main() {
  clear_screen();

  pic_remap();

  set_idt_gate(0x20, (unsigned)isr0);
  set_idt_gate(0x21, (unsigned)isr1);

  set_idt();

  init_timer(2);

  __asm__ volatile("sti");

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  shell_init();

  while(1);
}
