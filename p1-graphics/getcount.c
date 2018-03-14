#include "types.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char* argv[])
{
  printf(1, "Initial fork count %d\n", getcount(SYS_fork));

  if (fork() == 0) {
    printf(1, "Child fork count %d\n", getcount(SYS_fork));
    printf(1, "Child write count %d\n", getcount(SYS_write));
  } else {
    wait();
    printf(1, "Parent fork count %d\n", getcount(SYS_fork));
    printf(1, "Parent write cound %d\n", getcount(SYS_write));
  }

  printf(1, "Wait count %d\n", getcount(SYS_wait));
  exit();
}
