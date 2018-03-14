#include "types.h"
#include "user.h"
#include "syscall.h"


int main()
{
  printf(1, "init_graphics returned:        %d\n", init_graphics());
  printf(1, "exit_graphics returned:        %d\n", exit_graphics());
  printf(1, "getkey returned:               %d\n", getkey());
  printf(1, "clear_screen returned:         %d\n", clear_screen());
  printf(1, "draw_pixel(1,2,3) returned:    %d\n", draw_pixel(1,2,3));
  printf(1, "draw_line(1,2,3,4,5) returned: %d\n", draw_line(1,2,3,4,5));
  printf(1, "blit() returned:               %d\n", blit());
  exit();
}
