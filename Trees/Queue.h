#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if (q->rear == q->size - 1)
        printf("Queue is full\n");
    else
        q->Q[++q->rear] = x;
}

struct Node *dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    else
        return q->Q[++q->front];
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

#endif
