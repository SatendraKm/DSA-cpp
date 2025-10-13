#include <iostream>
#include <cstring> // for strlen
using namespace std;

int main()
{
    char A[] = "madam";
    char B[6]; // same length as A (5 letters + '\0')

    // ------------ Method 1: Reverse and Compare ------------
    int i, j;
    for (i = 0; A[i] != '\0'; i++)
    {
    }          // find length manually
    i = i - 1; // last valid index
    for (j = 0; i >= 0; i--, j++)
        B[j] = A[i];

    B[j] = '\0'; // null terminate the reversed string

    cout << "Reversed string: " << B << endl;

    // compare
    if (strcmp(A, B) == 0)
        cout << "Method-1: Palindrome ✅" << endl;
    else
        cout << "Method-1: Not a palindrome ❌" << endl;

    // ------------ Method 2: Two-pointer technique ------------
    int left = 0;
    int right = strlen(A) - 1;
    bool isPalindrome = true;

    while (left < right)
    {
        if (A[left] != A[right])
        {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        cout << "Method-2: Palindrome ✅" << endl;
    else
        cout << "Method-2: Not a palindrome ❌" << endl;

    return 0;
}
