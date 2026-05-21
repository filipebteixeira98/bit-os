#include "screen.h"
#include "idt.h"
#include "pic.h"
#include "shell.h"
#include "timer.h"
#include "memory.h"
#include "paging.h"

extern void isr0();
extern void isr1();
extern void isr14();

void kernel_main() {
  clear_screen();

  pic_remap();

  set_idt_gate(0x20, (unsigned)isr0);
  set_idt_gate(0x21, (unsigned)isr1);
  set_idt_gate(14, (unsigned)isr14);

  set_idt();

  init_timer(100);

  __asm__ volatile("sti");

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  shell_init();

  initialize_paging();

  while(1);
}
