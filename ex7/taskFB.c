
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
// Note the argument and return types: void*

long global_variable = 0;
pthread_mutex_t mtx1, mtx2, mtx3, mtx4, mtx5;
bool fork1=0, fork2=0, fork3=0, fork4=0, fork5=0;
bool eat1=0, eat2=0, eat3=0, eat4=0, eat5=0;

void *philosopher1(void* args)
    {   
        int mtx1_locked, mtx2_locked;

        while (1)
        {
            mtx1_locked=1;
            mtx2_locked=1;
            while (mtx1_locked!=0 || mtx2_locked!=0)
            {
                mtx1_locked=1;
                mtx2_locked=1;
                usleep(1);
                mtx1_locked = pthread_mutex_trylock(&mtx1);
                if (mtx1_locked==0)
                {
                    mtx2_locked = pthread_mutex_trylock(&mtx2);
                }
                
                if (mtx2_locked!=0 && mtx1_locked==0)
                {
                    pthread_mutex_unlock(&mtx1);
                }
            }
            printf("Philosopher 1 has locked F1 and F2\n");
            eat1=1;
            printf("Philosopher 1 is now eating!\n");
            pthread_mutex_unlock(&mtx1);
            pthread_mutex_unlock(&mtx2);
            printf("Philosopher 1 releases fork 1 and 2\n");
        }
        
        
        return NULL;
    }

void *philosopher2(void* args)
    {
        int mtx2_locked, mtx3_locked;

        while (1)
        {
            mtx2_locked=1;
            mtx3_locked=1;
            while (mtx2_locked!=0 || mtx3_locked!=0)
            {
                mtx2_locked=1;
                mtx3_locked=1;
                usleep(1);
                mtx2_locked = pthread_mutex_trylock(&mtx2);
                if (mtx2_locked==0)
                {
                    mtx3_locked = pthread_mutex_trylock(&mtx3);
                }
                
                if (mtx3_locked!=0 && mtx2_locked==0)
                {
                    pthread_mutex_unlock(&mtx2);
                }
            }
            printf("Philosopher 2 has locked F2 and F3\n");
            eat2=1;
            printf("Philosopher 2 is now eating!\n");
            pthread_mutex_unlock(&mtx2);
            pthread_mutex_unlock(&mtx3);
            printf("Philosopher 2 releases fork 2 and 3\n");
        }
        
        
        return NULL;
    }

void *philosopher3(void* args)
    {
        int mtx3_locked, mtx4_locked;

        while (1)
        {
            mtx3_locked=1;
            mtx4_locked=1;
            while (mtx3_locked!=0 || mtx4_locked!=0)
            {
                mtx3_locked=1;
                mtx4_locked=1;
                usleep(1);
                mtx3_locked = pthread_mutex_trylock(&mtx3);
                if (mtx3_locked==0)
                {
                    mtx4_locked = pthread_mutex_trylock(&mtx4);
                }
                
                if (mtx4_locked!=0 && mtx3_locked==0)
                {
                    pthread_mutex_unlock(&mtx3);
                }
            }
            printf("Philosopher 3 has locked F3 and F4\n");
            eat3=1;
            printf("Philosopher 3 is now eating!\n");
            pthread_mutex_unlock(&mtx3);
            pthread_mutex_unlock(&mtx4);
            printf("Philosopher 3 releases fork 3 and 4\n");
        }
        
        
        
        return NULL;
    }

void *philosopher4(void* args)
    {
       int mtx4_locked, mtx5_locked;

        while (1)
        {
            mtx4_locked=1;
            mtx5_locked=1;
            while (mtx4_locked!=0 || mtx5_locked!=0)
            {
                mtx4_locked=1;
                mtx5_locked=1;
                usleep(1);
                mtx4_locked = pthread_mutex_trylock(&mtx4);
                if (mtx4_locked==0)
                {
                    mtx5_locked = pthread_mutex_trylock(&mtx5);
                }
                
                if (mtx5_locked!=0 && mtx4_locked==0)
                {
                    pthread_mutex_unlock(&mtx4);
                }
            }
            printf("Philosopher 4 has locked F4 and F5\n");
            eat4=1;
            printf("Philosopher 4 is now eating!\n");
            pthread_mutex_unlock(&mtx4);
            pthread_mutex_unlock(&mtx5);
            printf("Philosopher 4 releases fork 4 and 5\n");
        }
        
        
        return NULL;
    }

void *philosopher5(void* args)
    {
       int mtx5_locked, mtx1_locked;

        while (1)
        {
            mtx5_locked=1;
            mtx1_locked=1;
            while (mtx5_locked!=0 || mtx1_locked!=0)
            {
                mtx5_locked=1;
                mtx1_locked=1;
                usleep(1);
                mtx5_locked = pthread_mutex_trylock(&mtx5);
                if (mtx5_locked==0)
                {
                    mtx1_locked = pthread_mutex_trylock(&mtx1);
                }
                
                if (mtx1_locked!=0 && mtx5_locked==0)
                {
                    pthread_mutex_unlock(&mtx5);
                }
            }
            printf("Philosopher 5 has locked F5 and F1\n");
            eat5=1;
            printf("Philosopher 5 is now eating!\n");
            pthread_mutex_unlock(&mtx5);
            pthread_mutex_unlock(&mtx1);
            printf("Philosopher 5 releases fork 5 and 1\n");
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

        pthread_mutex_destroy(&mtx1);
        pthread_mutex_destroy(&mtx2);
        pthread_mutex_destroy(&mtx3);
        pthread_mutex_destroy(&mtx4);
        pthread_mutex_destroy(&mtx5);
        

        return 0;
        
    }
    


 
//We have a so called race condition