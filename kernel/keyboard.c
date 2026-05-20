#include "ports.h"
#include "screen.h"
#include "pic.h"
#include "shell.h"

char keymap[128] = {
    0,
    27,
    '1','2','3','4','5','6','7','8','9','0',
    '-','=',
    '\b',
    '\t',
    'q','w','e','r','t','y','u','i','o','p',
    '[',']',
    '\n',
    0,
    'a','s','d','f','g','h','j','k','l',
    ';','\'','`',
    0,
    '\\',
    'z','x','c','v','b','n','m',
    ',', '.', '/',
    0,
    '*',
    0,
    ' '
};

void keyboard_handler() {
  unsigned char scancode = port_byte_in(0x60);

  if (scancode > 57) {
    pic_send_eoi(1);
    return;
  }

  char letter = keymap[scancode];

  shell_handle_char(letter);

  pic_send_eoi(1);
}
