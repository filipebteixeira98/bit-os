#include "screen.h"

void kernel_main() {
  clear_screen();

  print("Bit-OS Kernel\n");
  print("Protected Mode Activated\n");

  while(1);
}
