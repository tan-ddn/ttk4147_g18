
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
// Note the argument and return types: void*

long global_variable = 0;
sem_t sem;

void* fn(void* args)
    {
        long local_variable = 0;

        for(int i = 0; i<50000000; i++)
        {
            global_variable++;
            local_variable++;
        }   
            printf("\nglobal number %ld", global_variable);
            printf("\nlocal number %ld", local_variable);

    return NULL;
    }
      
int main()
    {
        
        pthread_t thread1, thread2;
        
        pthread_create(&thread1, NULL, fn, NULL);
        pthread_create(&thread2, NULL, fn, NULL);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }
    


 
//We have a so called race condition