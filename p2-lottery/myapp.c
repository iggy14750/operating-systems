
#include "types.h"
#include "user.h"

int main() {
  settickets(2);
  if (fork() == 0) {
    // child
  } else {
    settickets(3);
  }
  wait();
  sleep(100);
  exit();
}