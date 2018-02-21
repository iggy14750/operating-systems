#include "types.h"
#include "user.h"
#include "syscall.h"
#include "graphics.h"

struct sprite {
  int x;
  int y;
};

void draw(struct sprite s)
{
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      draw_pixel(8*s.x + i, 8*s.y + j, DARK_RED);
    }
  }
}

int main()
{
  int c = 1;
  struct sprite s = {
    .x = 40,
    .y = 30,
  };
  init_graphics();
  while (1) {
    c = getkey();
    printf(1, "%d\n", c);
    switch (c) {
      case 'w':
        s.y--;
        break;
      case 'd':
        s.x++;
        break;
      case 's':
        s.y++;
        break;
      case 'a':
        s.x--;
        break;
      case -1:
        break;
      case 'p':
        goto exit;
    }
    clear_screen();
    draw(s);
    blit();
    sleep(1); // 100 cycles = ~1 second
  }
exit:
  exit_graphics();
  exit();
}
