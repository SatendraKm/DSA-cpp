#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
    printf("%d enqueued\n", x);
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    printf("Queue: ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    display();
    enqueue(20);
    display();
    enqueue(30);
    display();
    enqueue(40);
    display();
    enqueue(50);
    display();
    enqueue(60);
    display();
    printf("%d left the queue\n", dequeue());
    display();
    printf("%d left the queue\n", dequeue());
    display();
    printf("%d left the queue\n", dequeue());
    display();
    return 0;
}