#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "io.h"


void *take_response( void *ptr );

int main() {

    io_init();
   
    pthread_t threadA, threadB, threadC;

    iretA = pthread_create( &threadA, NULL, take_responseA, NULL);
    iretB = pthread_create( &threadB, NULL, take_responseB, NULL);
    iretC = pthread_create( &threadB, NULL, take_responseC, NULL);

    pthread_join();
}


void *take_responseA( void *vargp )
{
    while(1) {
        if (io_read(1) == 0) {
            io_write(1,0);
            io_write(1,1);
        }
    }
}

void *take_responseB( void *vargp )
{
    while(1) {
        if (io_read(2) == 0) {
            io_write(2,0);
            io_write(2,1);
        }
    }
}

void *take_responseC( void *vargp )
{
    while(1) {
        if (io_read(3) == 0) {
            io_write(3,0);
            io_write(3,1);
        }
    }
}