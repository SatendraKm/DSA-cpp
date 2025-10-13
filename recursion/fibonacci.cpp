#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int Ifibonacci(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if (n <= 1)
    {
        return n;
    }
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int Memofibonacci(int n)
{
    static const int MAX = 1000;
    static int F[MAX];
    static bool initialized = false;
    if (!initialized)
    {
        for (int i = 0; i < MAX; i++)
            F[i] = -1;
        initialized = true;
    }
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = Memofibonacci(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = Memofibonacci(n - 1);
        }
    }
    F[n] = F[n - 2] + F[n - 1];
    return F[n - 2] + F[n - 1];
}

int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "fibonacci of " << num << " using recursion is " << fibonacci(num) << endl;
    cout << "fibonacci of " << num << " using loops is " << Ifibonacci(num) << endl;
    cout << "fibonacci of " << num << " using memoized recursion is " << Memofibonacci(num) << endl;
    return 0;
}
