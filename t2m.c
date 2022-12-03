#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

static int count=0;

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;



void insert(int data) {

    struct node *link = (struct node*) malloc(sizeof(struct node));
            
    link->data = data;
    link->next = head;
    head = link;

    count++;

}

pthread_t tid[4];
pthread_mutex_t lock;

void *add(void *arg)
{   
    pthread_mutex_lock(&lock);


    for (int i=0; i<10000;i++){

        insert(1);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}


int main()
{
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 4; i++)
    {
        pthread_create(&(tid[i]), NULL, add, (void*)&tid[i]);
        
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("Count = %d", count);
    pthread_mutex_destroy(&lock);

    return 0;
}
