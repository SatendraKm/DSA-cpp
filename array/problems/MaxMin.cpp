// NOTE: Sorted array
// IDEA: finding maximum and minimum in a single scan
// time complexity to O(n)

// // HACK:
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int A[n] = {0, 1, 5, 8, 4};
    int min, max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        else if (A[i] > max)
        {
            max = A[i];
        }
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    return 0;
}