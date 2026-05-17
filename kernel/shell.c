#include "shell.h"
#include "screen.h"

#define MAX_COMMAND_LENGTH 256

char command_buffer[MAX_COMMAND_LENGTH];

int command_index = 0;

void shell_init() {
  print("> ");
}

int strcmp(const char *a, const char *b) {
  int i = 0;

  while (a[i] && b[i]) {
    if (a[i] != b[i]) 
      return 0;
  
    i++;
  }

  return a[i] == b[i];
}
