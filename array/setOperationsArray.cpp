// this is the program which contains functions for union, intersection and difference of two arrays
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr->A[k++] = arr2->A[j++];
        else
        {
            arr->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr->A[k++] = arr1->A[i];
    }
    for (; j < arr->length; j++)
    {
        arr->A[k++] = arr2->A[j];
    }
    arr->length = k;
    arr->size = 10;
    return arr;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr->length = k;
    arr->size = 10;
    return arr;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr->A[k++] = arr1->A[i];
    }
    arr->length = k;
    arr->size = 10;
    return arr;
}

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
    struct Array *arr3;
    struct Array *arr4;
    struct Array *arr5;

    printf("first array");
    Display(arr1);
    printf("second array");
    Display(arr2);

    arr3 = Union(&arr1, &arr2);
    printf("union of arrays: ");
    Display(*arr3);

    arr4 = Intersection(&arr1, &arr2);
    printf("Intersection of arrays: ");
    Display(*arr4);

    arr5 = Difference(&arr1, &arr2);
    printf("Difference of arrays: ");
    Display(*arr5);

    return 0;
}