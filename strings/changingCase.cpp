// get the length of the string;
#include <iostream>
using namespace std;

// NOTE: the difference between uppercase and lowercase is 32
// we have to add 32 to the characters
// int main()
// {
//     char S[] = "WELCOME";
//     int i;
//     for (i = 0; S[i] != '\0'; i++)
//     {
//         S[i] = S[i] + 32;
//     }
//     cout << "Lowercase string is: " << S << endl;

//     return 0;
// }

// subtracting 32 will give lowercase

// OPTIMIZE: how to toggle the cases of the characters
int main()
{
    char S[] = "WELCOME";
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
        if (S[i] >= 65 && S[i] <= 90)
        {
            S[i] += 32;
        }
        else if (S[i] >= 'a' && S[i] <= 122)
        {
            S[i] -= 32;
        }
    }
    cout << "Toggled string is: " << S << endl;

    return 0;
}