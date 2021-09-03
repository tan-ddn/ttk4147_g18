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
		int t1 = __rdtsc();
	}
	
    return 0;
}
