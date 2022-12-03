#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_t tid[10];

void *counter(void *arg)
{
    
    static int count=10;
   
    count++;
    
    printf("Count = %d\n",count);
    return NULL;
}


int main()
{
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&(tid[i]), NULL, counter, (void*)&tid[i]);
        
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(tid[i], NULL);
    }
    
}