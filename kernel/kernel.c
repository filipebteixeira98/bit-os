#include "screen.h"
#include "idt.h"
#include "pic.h"
#include "shell.h"
#include "timer.h"
#include "memory.h"
#include "paging.h"

extern void isr0();
extern void isr1();

void kernel_main() {
  clear_screen();

  pic_remap();

  set_idt_gate(0x20, (unsigned)isr0);
  set_idt_gate(0x21, (unsigned)isr1);

  set_idt();

  init_timer(100);

  __asm__ volatile("sti");

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  shell_init();

  char* test = (char*) kmalloc(6);

  test[0] = 'H';
  test[1] = 'e';
  test[2] = 'l';
  test[3] = 'l';
  test[4] = 'o';
  test[5] = '\0';

  print(test);

  initialize_paging();

  while(1);
}
