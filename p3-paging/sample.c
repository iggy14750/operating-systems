#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  printf(1, "Hellooo\n");
  int *buf = sbrk(4096);
  int i;
  for(i = 0; i < 4095; i++){
    *buf = (int) 'a';
  }

  exit();
}
