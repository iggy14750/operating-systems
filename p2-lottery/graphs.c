#include "types.h"
#include "user.h"
#include "pstat.h"

// Spawns two child processes so that the three
// have a 1:2:3 relationship in terms of tickets.
int main() {
    settickets(10);
    if (fork() == 0) {
        settickets(20);
        while (1);
    } else if (fork() == 0) {
        settickets(30);
        while (1);
    } else {
        while (1);
    }
}