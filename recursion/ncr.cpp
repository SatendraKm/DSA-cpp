#include <iostream>
using namespace std;

// recursive factorial function
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// int nCr(int n, int r)
// {
//     int num, den;
//     num = factorial(n);
//     den = factorial(r) * factorial(n - r);
//     return num / den;
// }

// recursive combinatino function
int nCr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    cout << "combination" << " is " << nCr(4, 2) << endl;
    return 0;
}
