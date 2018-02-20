#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  init_graphics();
  for (int i = 0; i < 16; i++) {
    draw_pixel(320+i, 240, i);
  }
  blit();
  sleep(500); // 100 cycles = ~1 second
  exit_graphics();
  exit();
}
