#include <iostream>
using namespace std;

// NOTE: basic approach
// int main()
// {
//     char A[] = "python";
//     char B[7];
//     int i, j;
//     for (i = 0; A[i] != '\0'; i++)
//     {
//     }
//     i = i - 1;
//     for (j = 0; i >= 0; i--, j++)
//     {
//         B[j] = A[i];
//     }
//     B[j] = '\0';
//     cout << "original: " << A << endl;
//     cout << "reversed: " << B << endl;

//     return 0;
// }

// OPTIMIZE: doing inplace reverse by exchaing the 1 <-> n-1, 2 <-> (n-2)... elements
int main()
{
    char A[] = "python";
    cout << "original: " << A << endl;
    char B[7];
    int i, j;
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    i = 0;
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << "reversed: " << A << endl;

    return 0;
}