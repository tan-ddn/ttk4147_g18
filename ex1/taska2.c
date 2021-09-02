#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("usleep function: waits for 1 second.");
    usleep(1000000);
    return 0;
}
