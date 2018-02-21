#include "types.h"
#include "user.h"
#include "syscall.h"
#include "graphics.h"

struct {
  int x;
  int y;
} pixel;

int main()
{
  int c = 1;
  pixel.x = 320;
  pixel.y = 240;
  init_graphics();
  while (1) {
    c = getkey();
    printf(1, "%d\n", c);
    switch (c) {
      case 'w':
        pixel.y--;
        break;
      case 'd':
        pixel.x++;
        break;
      case 's':
        pixel.y++;
        break;
      case 'a':
        pixel.x--;
        break;
      case -1:
        break;
      case 'p':
        goto exit;
    }
    clear_screen();
    draw_pixel(pixel.x, pixel.y, DARK_RED);
    blit();
    sleep(20); // 100 cycles = ~1 second
  }
exit:
  exit_graphics();
  exit();
}
