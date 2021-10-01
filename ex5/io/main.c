#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include "io.h"




int set_cpu(int cpu_number);
void *take_responseA( void *vargp );
void *take_responseB( void *vargp );
void *take_responseC( void *vargp );
void *distrubance_thread( void *vargp );

int main() {

    io_init();
   
    pthread_t threadA, threadB, threadC;
    pthread_t d[10];

    pthread_create( &threadA, NULL, take_responseA, NULL);
    pthread_create( &threadB, NULL, take_responseB, NULL);
    pthread_create( &threadB, NULL, take_responseC, NULL);

    for(int current_t = 0; current_t < 10; current_t++)
    {
        pthread_create(&d[current_t], NULL, distrubance_thread, NULL);
    }


    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);


    for(int current_t = 0; current_t < 10; current_t++)
    {
        pthread_join(d[current_t], NULL);
    }

    exit(0);
}


void *take_responseA( void *vargp )
{
    set_cpu(1);
    while(1) {
        asm volatile("" ::: "memory");
        if (io_read(1) == 0) {
            io_write(1,0);
            io_write(1,1);
        }
    }
}

void *take_responseB( void *vargp )
{
    set_cpu(1);
    while(1) {
        asm volatile("" ::: "memory");
        if (io_read(2) == 0) {
            io_write(2,0);
            io_write(2,1);
        }
    }
}

void *take_responseC( void *vargp )
{
    set_cpu(1);
    while(1) {
        asm volatile("" ::: "memory");
        if (io_read(3) == 0) {
            io_write(3,0);
            io_write(3,1);
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
    set_cpu(1);
    while(1) {
        asm volatile("" ::: "memory");
    }
}