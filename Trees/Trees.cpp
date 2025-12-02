#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void TreeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        p = dequeue(&q);

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Ipreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void IPostorder(struct Node *p)
{
    long temp;
    struct Stack stk;
    StackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            temp = (long)pop(&stk);

            if (temp > 0)
            {
                push(&stk, (struct Node *)(-temp));
                p = ((struct Node *)temp)->rchild;
            }
            else
            {
                struct Node *node = (struct Node *)(-temp);
                printf("%d ", node->data);
                p = NULL;
            }
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);
    while (!isEmpty(&q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int Count(struct Node *root)
{
    if (root)
    {
        return Count(root->lchild) + Count(root->rchild) + 1;
    }
    return 0;
}

int Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    TreeCreate();
    // printf("\nLevelOrder Traversal: ");
    // LevelOrder(root);
    printf("\nCount: %d", Count(root));
    printf("\nHeight: %d", Height(root));
    printf("\n");
    return 0;
}
