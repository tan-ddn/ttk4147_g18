
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
// Note the argument and return types: void*

long global_variable = 0;
pthread_mutex_t mtx1, mtx2, mtx3, mtx4, mtx5;
bool fork1=0, fork2=0, fork3=0, fork4=0, fork5=0;
bool eat1=0, eat2=0, eat3=0, eat4=0, eat5=0;

void *philosopher1(void* args)
    {   
        while (1)
      {
        printf("P1 requires fork 1\n");
        pthread_mutex_lock(&mtx1);
        fork1 =  1;
        printf("P1 has fork 1\n");
        printf("P1 requires fork 2\n");
        pthread_mutex_lock(&mtx2);
        printf("P1 has fork 2\n");
        fork2 = 1;
        printf("Philosopher 1 is now eating!\n");
        eat1=1;
        fork1 = 0;
        pthread_mutex_unlock(&mtx1);
        printf("P1 releases fork 1\n");
        fork2 = 0;
        pthread_mutex_unlock(&mtx2);
        printf("P1 releases fork 2\n");
      }
      
        return NULL;
    }

void *philosopher2(void* args)
    {
        while (1)
        {
        printf("P2 requires fork 2\n");
        pthread_mutex_lock(&mtx2);
        fork2 =  1;
        printf("P2 has fork 2\n");
        printf("P2 requires fork 3\n");
        pthread_mutex_lock(&mtx3);
        printf("P2 has fork 3\n");
        fork3 = 1;
        printf("Philosopher 2 is now eating!\n");
        eat2=1;
        fork2 = 0;
        pthread_mutex_unlock(&mtx2);
        printf("P2 releases fork 2\n");
        fork3 = 0;
        pthread_mutex_unlock(&mtx3);
        printf("P2 releases fork 3\n");
        }
        
        return NULL;
    }

void *philosopher3(void* args)
    {
       while (1)
       {
           printf("P3 requires fork 3\n");
        pthread_mutex_lock(&mtx3);
        fork3 =  1;
        printf("P3 has fork 3\n");
        printf("P3 requires fork 4\n");
        pthread_mutex_lock(&mtx4);
        printf("P3 has fork 4\n");
        fork4 = 1;
        printf("Philosopher 3 is now eating!\n");
        eat3=1;
        fork3 = 0;
        pthread_mutex_unlock(&mtx3);
        printf("P3 releases fork 3\n");
        fork4 = 0;
        pthread_mutex_unlock(&mtx4);
        printf("P3 releases fork 4\n");
       }
       
        return NULL;
    }

void *philosopher4(void* args)
    {
       while (1)
       {
           printf("P4 requires fork 4\n");
            pthread_mutex_lock(&mtx4);
            fork4 =  1;
            printf("P4 has fork 4\n");
            printf("P4 requires fork 5\n");
            pthread_mutex_lock(&mtx5);
            printf("P4 has fork 5\n");
            fork5 = 1;
            printf("Philosopher 4 is now eating!\n");
            eat4=1;
            fork4 = 0;
            pthread_mutex_unlock(&mtx4);
            printf("P4 releases fork 4\n");
            fork5 = 0;
            pthread_mutex_unlock(&mtx5);
            printf("P4 releases fork 5\n");
       }
       
        return NULL;
    }

void *philosopher5(void* args)
    {
       while (1)
       {
            printf("P5 requires fork 5\n");
            pthread_mutex_lock(&mtx5);
            fork5 =  1;
            printf("P5 has fork 5\n");
            printf("P5 requires fork 1\n");
            pthread_mutex_lock(&mtx1);
            printf("P5 has fork 1\n");
            fork1 = 1;
            printf("Philosopher 5 is now eating!\n");
            eat5=1;
            fork5 = 0;
            pthread_mutex_unlock(&mtx5);
            printf("P5 releases fork 5\n");
            fork1 = 0;
            pthread_mutex_unlock(&mtx1);
            printf("P5 releases fork 1\n");
       }
       return NULL;
       
    }
      
int main()
    {
        
        pthread_t thread1, thread2, thread3, thread4, thread5;
        
        pthread_mutex_init(&mtx1,NULL);
        pthread_mutex_init(&mtx2,NULL);
        pthread_mutex_init(&mtx3,NULL);
        pthread_mutex_init(&mtx4,NULL);
        pthread_mutex_init(&mtx5,NULL);
        
        pthread_create(&thread1, NULL, philosopher1, NULL);
        pthread_create(&thread2, NULL, philosopher2, NULL);
        pthread_create(&thread3, NULL, philosopher3, NULL);
        pthread_create(&thread4, NULL, philosopher4, NULL);
        pthread_create(&thread5, NULL, philosopher5, NULL);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
        pthread_join(thread4, NULL);
        pthread_join(thread5, NULL);
        
        

        bool wait=false;
        while( !(eat1 && eat2 && eat3 && eat4 && eat5) ){
            wait = true;
        }

       /* bool wait=false;
        while (1)
        {
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);
            pthread_join(thread5, NULL);
           
        }*/
        
        pthread_mutex_destroy(&mtx1);
        pthread_mutex_destroy(&mtx2);
        pthread_mutex_destroy(&mtx3);
        pthread_mutex_destroy(&mtx4);
        pthread_mutex_destroy(&mtx5);
        

        return 0;
        
    }
    


 
//We have a so called race condition