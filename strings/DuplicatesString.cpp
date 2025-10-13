#include <iostream>
using namespace std;
// IDEA: there are three methods to find duplicates in an array of characters i.e string
// NOTE:
// 1. compare with other letters
// 2. using hashtable as counting- enter the ascii value
// 3. using bits

// METHOD-2: using hashtables
// int main()
// {
//     char A[] = "finding";
//     int H[26], i;
//     // subtract -97 while storing the value of the alphabet into hashtable so that we have to take only 0-25 size of the array
//     //
//     // and while retrieving the alphabet we should add +97 so that we get the actual value of the alphabet according to ascii

//     for (i = 0; A[i] != '\0'; i++)
//     {
//         H[A[i] - 97] += 1;
//     }
//     for (i = 0; i < 26; i++)
//     {
//         if (H[i] > 1)
//         {
//             cout << (char)(i + 97) << " occurs " << H[i] << " times" << endl;
//         }
//     }

//     return 0;
// }

// NOTE:
/*
1 byte - 8 bits
*/

// METHOD-3: using bitwise operations
int main()
{
    char A[] = "finding";
    long int H = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        // subtract 97 from the ascii code and set the bit on
        x = x << (A[i] - 'a');
        if ((x & H) > 0)
        {
            cout << "duplicate: " << A[i] << endl;
        }
        else
        {
            H = x | H;
        }
    }

    return 0;
}