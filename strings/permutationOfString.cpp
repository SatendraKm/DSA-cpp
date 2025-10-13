#include <iostream>
using namespace std;

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        cout << Res << endl;
    }
    else
    {

        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = x;
}

void swappingMethod(char s[], int l, int h)
{
    int i;
    if (l == h)
    {
        cout << s << endl;
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            swappingMethod(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    char s[] = "ABC";
    perm(s, 0);
    return 0;
}