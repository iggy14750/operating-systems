#include "types.h"
#include "user.h"
#include "syscall.h"

int main()
{
  printf(1, "Hellooo\n");
  void* mem = sbrk(4096);
  int i;
  for(i = 0; i < 4095; i++){
    mem = 'a';
  }

  exit();
}
