#include "shell.h"
#include "screen.h"

#define MAX_COMMAND_LENGTH 256

char command_buffer[MAX_COMMAND_LENGTH];

int command_index = 0;

void shell_init() {
  print("> ");
}
