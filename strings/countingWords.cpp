#include <iostream>
using namespace std;

int main()
{
    char A[] = "How are you";
    int i, word = 1;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
        {
            word++;
        }
    }
    cout << word << endl;

    return 0;
}

// if there are continous number of spaces then it is called
// whitespaces

// for whitespaces we have to deal with it seperately
// if previous one is also space then skip it