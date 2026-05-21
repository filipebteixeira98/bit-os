#include "memory.h"

unsigned int free_memory_addr = 0x100000;

void* kmalloc(unsigned int size) {
  unsigned int addr = free_memory_addr;

  free_memory_addr += size;

  return (void*) addr;
}
