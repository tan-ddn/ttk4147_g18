#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("nanosleep function: waits for 1 second.");
    long sec = 1;
    struct timespec reg = {
        tv_sec = (timer_t) sec
    };
    struct timespec rem = {
        tv_sec = (timer_t) sec
    };
    nanosleep(&reg, &rem);
    return 0;
}
