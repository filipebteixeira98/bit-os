#include "screen.h"
#include "ports.h"

#define VIDEO_MEMORY 0xB8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0F

int get_cursor() {
  port_byte_out(0x3D4, 14);

  int offset = port_byte_in(0x3D5) << 8;

  port_byte_out(0x3D4, 15);

  offset += port_byte_in(0x3D5);

  return offset * 2;
}

void set_cursor(int offset) {
  offset /= 2;

  port_byte_out(0x3D4, 14);
  port_byte_out(0x3D5, (unsigned char)(offset >> 8));

  port_byte_out(0x3D4, 15);
  port_byte_out(0x3D5, (unsigned char)(offset & 0xff));
}

void print_char(char c) {
  char *video_memory = (char*) VIDEO_MEMORY;

  int offset = get_cursor();

  if (c == '\n') {
    int rows = offset / (2 * MAX_COLS);

    offset = 2 * MAX_COLS * (rows + 1);
  } else {
    video_memory[offset] = c;
    video_memory[offset + 1] = WHITE_ON_BLACK;
    offset += 2;
  }

  set_cursor(offset);
}

void print(const char *str) {
  int i = 0;

  while (str[i] != '\0') {
    print_char(str[i]);

    i += 1;
  }
}

void clear_screen() {
  char *video_memory = (char*) VIDEO_MEMORY;

  for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i += 2) {
    video_memory[i] = ' ';
    video_memory[i + 1] = WHITE_ON_BLACK;
  }

  set_cursor(0);
}
