#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <x86intrin.h>
#include <string.h>

#pragma intrinsic(__rdtsc)

int main()
{
	
	for(int i = 0; i < 10*1000*1000; i++){
		struct timespec now;
		int t1 = clock_gettime(CLOCK_MONOTONIC, &now);
	}
	
    return 0;
}
