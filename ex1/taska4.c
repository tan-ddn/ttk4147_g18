#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "busy_wait.h"

int main()
{
    printf("busy_wait function: waits for 1 second.");
    struct timespec t;
    busy_wait(1);
    return 0;
}
