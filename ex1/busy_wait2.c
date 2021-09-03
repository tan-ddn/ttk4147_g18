#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

void busy_wait(int t){
	struct tms org = {0};
    struct tms *org_p;
    org_p = &org;
	long int now = times(org_p);
	long int then = 0;
	while((then - now) < 100*t){
		for(int i = 0; i < 10000; i++){}
		then = times(org_p);
	}
}

