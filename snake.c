#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  printf(1, "first messagen\n");
  sleep(100); // 100 cycles = ~1 second
  printf(1, "second message\n");
  exit();
}
