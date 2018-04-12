#include "types.h"
#include "user.h"
#include "syscall.h"
#include "kalloc.c"

int main()
{
  printf(1, "Hellooo\n");
  char *buf = kalloc();
  int i;
  for(i = 0; i < 4095; i++){
    *buf = 'a';
  }

  exit();
}
