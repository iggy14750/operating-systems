#include "types.h"
#include "user.h"
#include "syscall.h"

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
  sleep(500); // 100 cycles = ~1 second
  exit_graphics();
  exit();
}
