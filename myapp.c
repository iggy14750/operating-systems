#include "types.h"
#include "user.h"
#include "syscall.h"


int main()
{
  printf(1, "init_graphics returned: %d\n", init_graphics());
  printf(1, "exit_graphics returned: %d\n", exit_graphics());
  exit();
}
