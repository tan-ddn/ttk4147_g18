#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <x86intrin.h>
#include <string.h>
#include <sched.h>

#pragma intrinsic(__rdtsc)

int main(void)
{
	int ns_max = 1000;
	int histogram[ns_max];
	int ns;
	memset(histogram, 0, sizeof(int)*ns_max);
	
	for(int i = 0; i < 10*1000*1000; i++){
		struct timespec t1, t2;
		clock_gettime(CLOCK_MONOTONIC, &t1);
		sched_yield();
		clock_gettime(CLOCK_MONOTONIC, &t2);
		int ns = (t2.tv_nsec - t1.tv_nsec) * 1;
		if(ns >= 0 && ns < ns_max){
			histogram[ns]++;
		}
	}
	
	for(int i = 0; i < ns_max; i++){
		printf("%d\n", histogram[i]);
	}
	
    return 0;
}
