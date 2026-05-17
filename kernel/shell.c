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

void execute_command() {
  if (strcmp(command_buffer, "help")) {
    print("\nCommands:\n");
    print("help - show commands\n");
    print("clear - clear screen\n");
  } else if (strcmp(command_buffer, "clear")) {
    clear_screen();
  } else {
    print("\nUnknown command\n");
  }
}

void shell_handle_char(char c) {
  if (c == '\n') {
    command_buffer[command_index] = '\0';

    execute_command();

    command_index = 0;

    print("\n> ");

    return;
  }
}
