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

    printf("Main started to execute");
    io_init();
   
}

