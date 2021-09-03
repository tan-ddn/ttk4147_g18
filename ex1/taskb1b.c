#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <x86intrin.h>
#include <string.h>

#pragma intrinsic(__rdtsc)

int main()
{
	int ns_max = 50;
	int histogram[ns_max];
	int t1, t2, ns;
	memset(histogram, 0, sizeof(int)*ns_max);
	
	for(int i = 0; i < 10*1000*1000; i++){
		t1 = __rdtsc();
		t2 = __rdtsc();
		int ns = (t2 - t1) * 0.376;
		if(ns >= 0 && ns < ns_max){
			histogram[ns]++;
		}
	}
	
	for(int i = 0; i < ns_max; i++){
		printf("%d\n", histogram[i]);
	}
	
    return 0;
}
