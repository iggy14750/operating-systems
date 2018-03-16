#include "types.h"
#include "user.h"
#include "pstat.h"

#define P1_TICKETS 2
#define P2_TICKETS 4
#define P3_TICKETS 6
#define DATA_SIZE 10
#define STEP_SIZE 100

// Spawns two child processes so that the three
// have a 1:2:3 relationship in terms of tickets.
int main() {
    struct pstat ps;

    printf(1, "P1\tP2\tP3\n");

    if (fork() == 0) {
        settickets(P1_TICKETS);
        while (1);
    } else if (fork() == 0) {
        settickets(P2_TICKETS);
        while (1);
    } else if (fork() == 0) {
        settickets(P3_TICKETS);
        while (1);
    } else {
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        for (int dontuse = 0; dontuse < DATA_SIZE; dontuse++) {
            sleep(STEP_SIZE);
            getpinfo(&ps);
            for (int j = 0; j < NPROC; j++) {
                switch (ps.tickets[j]) {
                    case P1_TICKETS:
                        p1 = ps.ticks[j];
                        break;
                    case P2_TICKETS:
                        p2 = ps.ticks[j];
                        break;
                    case P3_TICKETS:
                        p3 = ps.ticks[j];
                        break;
                }
            }
            printf(1, "%d\t%d\t%d\n", p1, p2, p3);
        }
        exit();
    }
}