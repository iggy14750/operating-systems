#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  printf(1, "Hellooo\n");
  char *b, *oldbrk;
  oldbrk = sbrk(0);
  // printf(1, "oldbrk - %x\n", oldbrk);
  int i;
  for(i = 0; i < 100; i++){
    b = sbrk(1);
    *b = i;
    // printf(1, "i - %d\tb - %x\n", i, b);
  }
  // printf(1, "b - %d\n", *b);

  exit();
}
