#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  printf(1, "Hellooo\n");
  char *buf = sbrk();
  int i;
  for(i = 0; i < 4095; i++){
    *buf = 'a';
  }

  exit();
}
