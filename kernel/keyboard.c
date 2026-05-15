#include "ports.h"
#include "screen.h"

char keymap[] = {
    0,
    27,
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '-',
    '=',
    '\b',
    '\t',
    'q',
    'w',
    'e',
};

void keyboard_handler() {
  unsigned char scancode = port_byte_in(0x60);

  if (scancode > 57) {
    return;
  }

  char letter = keymap[scancode];

  print_char(letter);
}
