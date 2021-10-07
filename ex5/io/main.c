#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include "io.h"
#include <time.h>



int set_cpu(int cpu_number);
void *take_responseA( void *vargp );
void *take_responseB( void *vargp );
void *take_responseC( void *vargp );
void *distrubance_thread( void *vargp );
void *periodic_thread(void *vargp);
void timespec_add(struct timespec *t, long us);

struct timespec period = {.tv_sec = 0, .tv_nsec = 1000*1000};

int main() {

    io_init();
   
    pthread_t threadA, threadB, threadC;
    // pthread_t per_thread;
    pthread_t d[10];

    pthread_create( &threadA, NULL, take_responseA, NULL);
    pthread_create( &threadB, NULL, take_responseB, NULL);
    pthread_create( &threadB, NULL, take_responseC, NULL);
    // pthread_create( &per_thread, NULL, periodic_thread, NULL);



    // for(int current_t = 0; current_t < 10; current_t++)
    // {
    //     pthread_create(&d[current_t], NULL, distrubance_thread, NULL);
    // }


    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    // pthread_join(per_thread, NULL);

    // for(int current_t = 0; current_t < 10; current_t++)
    // {
    //     pthread_join(d[current_t], NULL);
    // }

    exit(0);
}


void *take_responseA( void *vargp )
{
    // set_cpu(1);
    struct timespec waketime;
    clock_gettime(CLOCK_REALTIME, &waketime);
    while(1) {
        if (io_read(1) == 0) {
            io_write(1,0);
            io_write(1,1);

            // sleep
            timespec_add(&waketime, period.tv_nsec/1000);
            clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &waketime, NULL);
        }
    }
}

void *take_responseB( void *vargp )
{
    // set_cpu(1);
    struct timespec waketime;
    clock_gettime(CLOCK_REALTIME, &waketime);
    while(1) {
        if (io_read(2) == 0) {
            io_write(2,0);
            io_write(2,1);

                // sleep
            timespec_add(&waketime, period.tv_nsec/1000);
            clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &waketime, NULL);
        }
    }
}

void *take_responseC( void *vargp )
{
    // set_cpu(1);
    struct timespec waketime;
    clock_gettime(CLOCK_REALTIME, &waketime);
    while(1) {
        if (io_read(3) == 0) {
            io_write(3,0);
            io_write(3,1);

           // sleep
            timespec_add(&waketime, period.tv_nsec/1000);
            clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &waketime, NULL); 
        }
    }
}


int set_cpu(int cpu_number){
    cpu_set_t cpu;
    CPU_ZERO(&cpu);
    CPU_SET(cpu_number, &cpu);
    return pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpu);
}

void *distrubance_thread( void *vargp )
{
    // set_cpu(1);

    //  struct timespec waketime;
    // clock_gettime(CLOCK_REALTIME, &waketime);
    while(1) {
        asm volatile("" ::: "memory");

        // timespec_add(&waketime, period.tv_nsec/1000);
        //     clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &waketime, NULL);
    }
}


void *periodic_thread(void *vargp){

    struct timespec waketime;
    // struct timespec period = {.tv_sec = 0, .tv_nsec = 500*1000*1000};

    clock_gettime(CLOCK_REALTIME, &waketime);

    while(1){
        printf("Doing periodic work - second %ld \n", waketime.tv_nsec);
        fflush(stdout);
        // sleep
        timespec_add(&waketime, period.tv_nsec/1000);
        clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &waketime, NULL);
    }

}




void timespec_add(struct timespec *t, long us){
    t->tv_nsec += us*1000;
    if(t->tv_nsec > 1000000000){
        t->tv_nsec = t->tv_nsec - 1000000000;
        t->tv_sec += 1;
    }
}
