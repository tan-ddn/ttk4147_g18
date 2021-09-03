#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "busy_wait.h"

int main()
{
    printf("busy_wait function: waits for 1 second.");
    struct timespec t = {1};
    busy_wait(t);
    return 0;
}
