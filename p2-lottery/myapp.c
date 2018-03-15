
#include "types.h"
#include "user.h"
#include "pstat.h"

int main() {
  struct pstat ps;
  settickets(2);
  getpinfo(&ps);
  printf(1, "Index\tInuse\tTickets\tPID\tTicks\n");
  for (int i = 0; i < NPROC; i++) {
    printf(1, "%d\t%d\t%d\t%d\t%d\n", i, 
      ps.inuse[i],
      ps.tickets[i],
      ps.pid[i],
      ps.ticks[i]
    );
  }
  exit();
}