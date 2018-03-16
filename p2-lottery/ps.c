
#include "types.h"
#include "user.h"
#include "pstat.h"

int main() {
  struct pstat ps;
  settickets(2);
  getpinfo(&ps);
  printf(1, "Index\tTickets\tPID\tTicks\n");
  for (int i = 0; i < NPROC; i++) {
    if (ps.inuse[i] == 0) continue;
    printf(1, "%d\t%d\t%d\t%d\n", i, 
      ps.tickets[i],
      ps.pid[i],
      ps.ticks[i]
    );
  }
  exit();
}