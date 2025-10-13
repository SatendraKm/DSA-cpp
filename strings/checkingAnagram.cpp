#include <iostream>
using namespace std;

// method 1- can be to check each and every string of the first into second one.
// but this has time complexity of n^2

// two strings based on same set of alphabets is called anagram

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int H[26] = {0};
    int i;

    // Count frequency of letters in A
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a'] += 1;
    }

    // Subtract frequency using B
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 'a'] -= 1;
        if (H[B[i] - 'a'] < 0)
        {
            cout << "Not an anagram" << endl;
            return 0;
        }
    }

    // Check all zeroes
    for (i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            cout << "Not an anagram" << endl;
            return 0;
        }
    }

    cout << "Its an Anagram" << endl;

    return 0;
}
