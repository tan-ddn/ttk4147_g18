#include <stdlib.h>

void busy_wait(struct timepsec t) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    struct timespec then = timespec_add(now, t);

    while(timepsec_cmp(now, then) < 0) {
        for(int i=0; i < 1000; i++) {}
        clock_gettime(CLOCK_MONOTONIC, &now);
    }
}

