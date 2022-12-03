#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[10];
pthread_mutex_t lock;
void *counter(void *arg)
{
   
    static int count=10;
    pthread_mutex_lock(&lock);


        count++;   
    
    
    printf("Count = %d\n",count);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&(tid[i]), NULL, counter, (void*)&tid[i]);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&lock);
}