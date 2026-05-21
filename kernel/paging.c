#include "paging.h"
#include "screen.h"

unsigned int page_directory[1024]
__attribute__((aligned(4096)));

unsigned int first_page_table[1024]
__attribute__((aligned(4096)));

void initialize_paging() {
  for (int i = 0; i < 1024; i++) {
    page_directory[i] = 0x00000002;
  }

  for (int i = 0; i < 1024; i++) {
    first_page_table[i] = (i * 0x1000) | 3;
  }

  page_directory[0] = ((unsigned int)first_page_table) | 3;

  __asm__ volatile("mov %0, %%cr3" : : "r"(page_directory));

  unsigned int cr0;

  __asm__ volatile("mov %%cr0, %0" : "=r"(cr0));

  cr0 |= 0x80000000;

  __asm__ volatile("mov %0, %%cr0" : : "r"(cr0));
}

void page_fault_handler() {
  unsigned int faulting_address;

  __asm__ volatile("mov %%cr2, %0" : "=r"(faulting_address));

  print("Page fault\n");

  while(1);
}
