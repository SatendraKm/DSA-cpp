#include <iostream>
using namespace std;

// method 1- can be to check each and every string of the first into second one.
// but this has time complexity of n^2

// two strings based on same set of alphabets is called anagram
int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if (A[i] - 97)
        {
            cout << "Not an anagram" << endl;
            break;
        }
    }
    if (B[i] == '\0')
    {
        cout << "Its Anagram" << endl;
    }

    return 0;
}
