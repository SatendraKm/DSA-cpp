#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    // default constructor
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    };
    // parameterized constructor
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    // destructor
    ~Array()
    {
        delete[] A;
    }
    // prototype of the functions
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int Sum();
    Array *Merge(Array arr2);
};

void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

Array *Array::Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    return arr3;
}

void Array::Display()
{
    int i;
    cout << "Elements are\n";
    for (i = 0; i < length; i++)
        cout << A[i];
    cout << "\n";
}

void Array::Insert(int index, int x)
{
    int i;

    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        cout << x << "deleted from the array\n";
    }
    return x;
}

int Array::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            return i;
        }
    }
    return -1;
}

int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
        total += A[i];
    return total;
}

int main()
{
    Array *arr1;
    int sz;
    cout << "Enter size of the array: ";
    cin >> sz;
    arr1 = new Array(sz);

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
            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter an index to delete element from \n";
            cout << "index: ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Element deleted: " << x << " from index: " << index << endl;
            break;
        case 3:
            cout << "Enter an element to search for: ";
            cin >> key;
            x = arr1->LinearSearch(key);
            cout << "Element: " << key << " found at index: " << x << endl;
            break;
        case 4:
            cout << "Sum of the elements are: " << arr1->Sum();
            break;
        case 5:
            arr1->Display();
            break;
        }
    } while (choice < 6);

    return 0;
}