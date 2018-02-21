#include "types.h"
#include "user.h"
#include "syscall.h"
#include "graphics.h"

int main()
{
  init_graphics();
  for (int color = 0; color < 16; color++) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        draw_pixel(320+(8*color)+i, 240+j, color);
      }
    }
  }
  blit();
  sleep(200); // 100 cycles = ~1 second

  clear_screen();
  draw_line(124, 130, 356, 272, DARK_RED);
  blit();
  sleep(300);
  exit_graphics();
  exit();
}
