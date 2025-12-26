#include <stdio.h>
#include "Chains.h"

int hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;
    for (i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    int key = 12;
    temp = Search(HT[hash(key)], key);

    if (temp == NULL)
    {
        printf("Key not found\n");
        return 1;
    }

    printf("search result- %d\n", temp->data);

    return 0;
}