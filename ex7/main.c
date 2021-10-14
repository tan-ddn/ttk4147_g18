
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
// Note the argument and return types: void*
/*
long global_number = 0;
sem_t sem;

void* fn(void* args)
    {
        long local_number = 0;

        for(int i = 0; i<50000000; i++)
        {
            sem_wait(&sem); 
            global_number++;
            sem_post(&sem);
            local_number++;

          
        }   
            printf("\nglobal number %ld", global_number);
            printf("\nlocal number %ld", local_number);

    return NULL;
    }
      
int main()
    {
        sem_init(&sem,0,1);
        pthread_t threadHandle;
        pthread_t threadHandle_2;

        pthread_create(&threadHandle, NULL, fn, NULL);
        pthread_create(&threadHandle_2, NULL, fn, NULL);

        pthread_join(threadHandle, NULL);
        pthread_join(threadHandle_2, NULL);
    }
    */

//to represent each fork
   pthread_mutex_t mtx1;
    pthread_mutex_t mtx2;
    pthread_mutex_t mtx3;
   pthread_mutex_t mtx4;
   pthread_mutex_t mtx5;



//each person is represented by a thread 
//we creat 4 thread functions

    void* fn1(void* args)
    {
        pthread_mutex_lock(&mtx1);
        pthread_mutex_lock(&mtx2);
        printf("\n The Phi. 1 Starts to eat");
        pthread_mutex_unlock(&mtx1);
        pthread_mutex_unlock(&mtx2);
        printf("\n The Phi. 1 finished eating");

        
    return NULL;
    }

  void* fn2(void* args)
    {
        pthread_mutex_lock(&mtx2);
        pthread_mutex_lock(&mtx3);
        printf("\n The Phi. 2 Starts to eat");
        pthread_mutex_unlock(&mtx2);
        pthread_mutex_unlock(&mtx3);
        printf("\n The Phi. 2 finished eating");

    return NULL;
    }

  void* fn3(void* args)
    {
        pthread_mutex_lock(&mtx3);
        pthread_mutex_lock(&mtx4);
        printf("\n The Phi. 3 Starts to eat");
        pthread_mutex_unlock(&mtx3);
        pthread_mutex_unlock(&mtx4);
        printf("\n The Phi. 3 finished eating");

        
    return NULL;
    }

  void* fn4(void* args)
    {
      pthread_mutex_lock(&mtx4);
        pthread_mutex_lock(&mtx5);
        printf("\n The Phi. 4 Starts to eat");
        pthread_mutex_unlock(&mtx4);
        pthread_mutex_unlock(&mtx5);
        printf("\n The Phi. 4 finished eating");

        
    return NULL;
    }

  void* fn5(void* args)
    {
       pthread_mutex_lock(&mtx5);
        pthread_mutex_lock(&mtx1);
        printf("\n The Phi. 5 Starts to eat");
        pthread_mutex_unlock(&mtx5);
        pthread_mutex_unlock(&mtx1);
        printf("\n The Phi. 5 finished eating");

        
    return NULL;
    }



   int main()
    {
        pthread_mutex_init(&mtx1,NULL);
        pthread_mutex_init(&mtx2,NULL);
        pthread_mutex_init(&mtx3,NULL);
        pthread_mutex_init(&mtx4,NULL);
        pthread_mutex_init(&mtx5,NULL);


        pthread_t threadHandle1;
        pthread_t threadHandle_2;
        pthread_t threadHandle_3;
        pthread_t threadHandle_4;
        pthread_t threadHandle_5;

        pthread_create(&threadHandle1, NULL, fn1, NULL);
        pthread_create(&threadHandle_2, NULL, fn2, NULL);
        pthread_create(&threadHandle_3, NULL, fn3, NULL);
        pthread_create(&threadHandle_4, NULL, fn4, NULL);
        pthread_create(&threadHandle_5, NULL, fn5, NULL);


        pthread_join(threadHandle1, NULL);
        pthread_join(threadHandle_2, NULL);
        pthread_join(threadHandle_3, NULL);
        pthread_join(threadHandle_4, NULL);
        pthread_join(threadHandle_5, NULL);


        pthread_mutex_destroy(&mtx1);
        pthread_mutex_destroy(&mtx2);
        pthread_mutex_destroy(&mtx3);
        pthread_mutex_destroy(&mtx4);
        pthread_mutex_destroy(&mtx5);
    }


