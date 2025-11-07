#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● C program for queue ●                             ║
//  ║                                                                              ║
//  ║                   • implementation in plain c language •                     ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝

/*
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full ");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty ");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    Display(q);
    printf("%d left\n", dequeue(&q));
    Display(q);
    return 0;
}
*/

//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                     ● C program for circular queue ●                         ║
//  ║                                                                              ║
//  ║                   • implementation of circular queue •                       ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full \n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    Display(q);
    printf("%d left\n", dequeue(&q));
    Display(q);
    return 0;
}

//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● C++ program for queue ●                           ║
//  ║                                                                              ║
//  ║                          • implementation in c++ •                           ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝

// class Queue
// {
// private:
//     int front;
//     int rear;
//     int size;
//     int *Q;

// public:
//     Queue();
//     Queue(int size);
//     ~Queue();
//     void enqueue(int x);
//     int dequeue();
//     void Display();
// };

// Queue::Queue()
// {
//     front = rear = -1;
//     size = 10;
//     Q = new int[size];
// }

// Queue::Queue(int size)
// {
//     front = rear = -1;
//     this->size = size;
//     Q = new int[this->size];
// }

// Queue::~Queue()
// {
//     delete[] Q;
// }

// void Queue::enqueue(int x)
// {
//     if (rear == size - 1)
//     {
//         cout << "Queue Full";
//     }
//     else
//     {
//         rear++;
//         Q[rear] = x;
//     }
// }

// int Queue::dequeue()
// {
//     int x = -1;
//     if (front == rear)
//     {
//         cout << "Queue Empty";
//     }
//     else
//     {
//         x = Q[front + 1];
//         front++;
//     }
//     return x;
// }
// void Queue::Display()
// {
//     for (int i = front + 1; i < rear; i++)
//     {
//         cout << Q[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     Queue q(5);
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.Display();
//     cout << "Element dequeued: " << q.dequeue() << endl;
//     q.Display();

//     return 0;
// }