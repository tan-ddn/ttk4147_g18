#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("nanosleep function: waits for 1 second.");
    struct timespec delay = {1};
    const struct timespec *reg;
    struct timespec *rem;
    reg = &delay;
    rem = &delay;
    nanosleep(reg, rem);
    return 0;
}
