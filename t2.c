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

void *add(void *arg)
{
    for (int i=0; i<10000;i++){

        insert(1);
    }
    return NULL;
}


int main()
{
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&(tid[i]), NULL, add, (void*)&tid[i]);
        
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("Count = %d", count);

    return 0;
}
