#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

// Note: function to create a lined list by using the elements of an array
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// Note: loop method to display elements of a linked list
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Note: function to display the elements of a linked list recursively
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}
// Note: counting the number of elements in a linked list
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
// Note: recursive method to find the count of elements
int Rcount(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rcount(p->next) + 1;
    }
}
// Note: function to get the sum of the elements of a liked list
int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
// Note: recursive function to get the sum of the elements
int Rsum(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next) + p->data;
    }
}
// Note: function to find the maximum element from the list
int max(struct Node *p)
{
    int m = INT_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}
// Note: recursive function to get the maximum element
int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT_MIN;
    }
    x = Rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

// Note: function to find the minimum element from the list
int min(struct Node *p)
{
    int m = INT_MAX;
    while (p)
    {
        if (p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}
// Note: recursive function to get the minimum element
int Rmin(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT_MAX;
    }
    x = Rmin(p->next);
    if (x < p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

// Note: function to perform linear search on a linked list
struct Node *LSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
// Note: recursive function for linear search on a linked list
struct Node *RLSearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return RLSearch(p->next, key);
}
// Optimize: Move to head optimization for linear search on a linked list
struct Node *MTFLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Note: function to insert a new element in a Linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}
// Note: function to insert an element always at the end of the list
void InsertLast(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
// Note: function to insert an element in a sorted linked list
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    // printf("Length is %d\n\n", Rcount(first));
    // printf("Sum is %d\n\n", Rsum(first));
    // printf("Maximum element is %d\n\n", Rmax(first));
    // printf("Minimum element is %d\n\n", Rmin(first));
    // struct Node *temp;
    // temp = MTFLSearch(first, 10);
    // if (temp)
    // {
    //     printf("Key-%d is found\n", temp->data);
    // }
    // else
    // {
    //     printf("Key is not found\n");
    // }
    // InsertLast(1);
    SortedInsert(first, 13);
    display(first);

    return 0;
}