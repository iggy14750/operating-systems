#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  init_graphics();
  clear_screen();
  for (int i = 0; i < 16; i++) {
    draw_pixel(320, 320+i, i);
  }
  blit();
  sleep(100); // 100 cycles = ~1 second
  exit_graphics();
  exit();
}
