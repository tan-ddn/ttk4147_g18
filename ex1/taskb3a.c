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
		struct tms t = {0};
		long int t1 = times(&t);
	}
	
    return 0;
}
