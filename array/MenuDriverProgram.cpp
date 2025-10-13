#include <stdio.h>
#include <iostream>
using namespace std;

struct Array
{
    int *A;
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
// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
// void Append(struct Array *arr, int x)
// {
//     if (arr->length < arr->size)
//         arr->A[arr->length++] = x;
// }
void Insert(struct Array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        printf("%d deleted from the array\n", x);
    }
    return x;
}

int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}
int Sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    return total;
}

int main()
{
    struct Array arr1;
    cout << "Enter size of the array: ";
    cin >> arr1.size;
    arr1.A = new int[arr1.size];
    arr1.length = 0;

    int choice;

    do
    {
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        int x, index, key;

        switch (choice)
        {
        case 1:
            cout << "Enter a value \n";
            cout << "x: ";
            cin >> x;
            cout << "Enter an index\n";
            cout << "index: ";
            cin >> index;
            Insert(&arr1, index, x);
            break;
        case 2:
            cout << "Enter an index to delete element from \n";
            cout << "index: ";
            cin >> index;
            x = Delete(&arr1, index);
            cout << "Element deleted: ", x, " from index: ", index;
            break;
        case 3:
            cout << "Enter an element to search for: ";
            cin >> key;
            x = LinearSearch(arr1, key);
            cout << "Element: ", key, " found at index: ", x;
            break;
        case 4:
            cout << "Sum of the elements are: " << Sum(arr1);
            break;

        case 5:
            Display(arr1);
        }
    } while (choice < 6);

    return 0;
}