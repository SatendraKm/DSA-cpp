#include <stdio.h>

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

int BinarySearch(int arr[], int x, int l, int h)
{

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x == arr[mid])
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int x, int l, int h)
{
    if (l <= h)
    {
        int mid;
        mid = (l + h) / 2;
        if (x == arr[mid])
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            return recursiveBinarySearch(arr, x, l, mid - 1);
        }
        else
        {
            return recursiveBinarySearch(arr, x, mid + 1, h);
        }
    }
    return -1;
}

int main()
{
    int l, h;
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    l = 0, h = arr.length - 1;
    Display(arr);
    printf("element found at the index %d using iterative function\n", BinarySearch(arr.A, 5, l, h));
    printf("element found at the index %d using recursive function\n", recursiveBinarySearch(arr.A, 5, l, h));
    return 0;
}