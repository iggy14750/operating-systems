#include "types.h"
#include "user.h"
#include "syscall.h"

char *new_prog[] = {
  "ls"
};

int main()
{
  printf(1, "Sample Test\n");
  int pid;
  char *a, *b, *c, *oldbrk;

  oldbrk = sbrk(0);
  printf(1, "oldbrk - %x\n", oldbrk);

  int i;
  for(i = 0; i < 4096; i++){
    b = sbrk(1);
    *b = i;
    // printf(1, "i - %d\tb - %x\n", i, b);
    // printf(1, "b - %d\n", *b);
  }

  // Deallocate
  a = sbrk(0);
  c = sbrk(-4096);
  if(c == (char*)0xffffffff){
    printf(1, "Did not deallocate\n");
    exit();
  }
  c = sbrk(0);
  if(c != a - 4096){
    printf(1, "Sbrk deallocation produced wrong address, a %x c %x\n", a, c);
    exit();
  }

  // Fork Test
  pid = fork();
  if(pid == 0){
    // child
    exec(new_prog[0], new_prog);
    exit();
  }
  wait();
  printf(1, "%s has pid %d\n", new_prog[0], pid);
  exit();
}
