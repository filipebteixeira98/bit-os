#include "timer.h"
#include "ports.h"
#include "screen.h"
#include "pic.h"

unsigned int tick = 0;

void timer_handler() {
  tick++;

  pic_send_eoi(0);
}

void init_timer(unsigned int frequency) {
  unsigned int divisor = 1193180 / frequency;

  port_byte_out(0x43, 0x36);

  unsigned char low = (unsigned char)(divisor & 0xFF);
  unsigned char high = (unsigned char)(divisor >> 8) & 0xFF;

  port_byte_out(0x40, low);
  port_byte_out(0x40, high);
}
