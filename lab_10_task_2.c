#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//pthread_mutex_t lock;
int sum = 0;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void add(int data)
{
    int number = data;

    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
    {
        new_node->data = number;
        head = new_node;
        head->next = NULL;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != NULL)
        {
             temp = temp->next;
        }

        temp->next = new_node;
        new_node->data = number;
        new_node->next = NULL;
    }
}


void *add_data(void *args)
{
    for(int i = 1; i < 10001; i++)
    {
        //pthread_mutex_lock(&lock);
        sum++;
        add(i);
        //pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void print()
{
    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d ->", temp->data);
	temp = temp->next;
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    pthread_t p1, p2, p3, p4;
    //pthread_mutex_init(&lock, NULL);

    pthread_create(&p1, NULL, add_data, NULL);
    pthread_create(&p2, NULL, add_data, NULL);
    pthread_create(&p3, NULL, add_data, NULL);
    pthread_create(&p4, NULL, add_data, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    //pthread_mutex_destroy(&lock);
    printf("Sum: %d\n", sum);

    return 0;
}
