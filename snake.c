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

  // Paint the town (screen) red
  clear_screen();
  for (int i = 320; i < 400; ++i) {
    for (int j = 240; j < 300; ++j) {
      draw_pixel(i, j, DARK_RED);
    }
  }
  blit();
  sleep(300);
  exit_graphics();
  exit();
}
