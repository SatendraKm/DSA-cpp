#include <iostream>
using namespace std;

int main()
{
    char A[] = "a e i o u d s b x";
    int i, vcount = 0, ccount = 0;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vcount++;
        }
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
        {
            ccount++;
        }
    }
    cout << "Vowels:" << vcount << endl;
    cout << "Consonants:" << ccount << endl;

    return 0;
}