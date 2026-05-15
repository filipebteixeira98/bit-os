#include "screen.h"

void kernel_main() {
  clear_screen();

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  extern void isr1();

  set_idt_gate(0x21, (unsigned)isr1);

  set_idt();

  while(1);
}
