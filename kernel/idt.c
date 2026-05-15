#include "idt.h"

void set_idt_gate(int n, unsigned int handler) {
  idt[n].low_offset = handler & 0xFFFF;
  idt[n].selector = 0x08;
  idt[n].always0 = 0;
  idt[n].flags = 0x8E;
  idt[n].high_offset = (handler >> 16) & 0xFFFF;
}

void set_idt() {
  idt_reg.base = (unsigned int) &idt;

  idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;

  __asm__ volatile("lidtl (%0)" : : "r" (&idt_reg));
}
