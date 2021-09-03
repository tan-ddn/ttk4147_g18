#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include "busy_wait2.h"

int main()
{
    printf("busy_wait function: waits for 1 second.\n");
    busy_wait(1);
    return 0;
}
