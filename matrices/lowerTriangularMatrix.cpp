#include <stdio.h>
#include <iostream>
using namespace std;

/*
Note: Row major representation in c

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return 0;
    }
}
void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", m.A[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int x;
    printf("Enter dimension");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("enter all elements ");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");

    Display(m);

    return 0;
}

*/

/*
// Note: Column major representation in c

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    }
    else
    {
        return 0;
    }
}
void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int x;
    printf("Enter dimension");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("enter all elements ");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");

    Display(m);

    return 0;
}
*/

// OPTIMIZE: C++ Codes for the lower triangular martix
/*
Note: row major representation

class LowerTri
{
private:
    int n;
    int *A;

public:
    LowerTri();
    LowerTri(int n);
    ~LowerTri();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; };
};
LowerTri::LowerTri()
{
    this->n = 2;
    A = new int[2 * (2 + 1) / 2];
}
LowerTri::LowerTri(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

LowerTri::~LowerTri()
{
    delete[] A;
}
void LowerTri::Set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
}

int LowerTri::Get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}
void LowerTri::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    LowerTri lm(d);

    int x;
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i, j, x);
        }
    }

    cout << "Diagonal Matrix:" << endl;
    lm.Display();

    return 0;
}
*/

// Note: column major representation

class LowerTri
{
private:
    int n;
    int *A;

public:
    LowerTri();
    LowerTri(int n);
    ~LowerTri();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; };
};
LowerTri::LowerTri()
{
    this->n = 2;
    A = new int[2 * (2 + 1) / 2];
}
LowerTri::LowerTri(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

LowerTri::~LowerTri()
{
    delete[] A;
}
void LowerTri::Set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x;
}

int LowerTri::Get(int i, int j)
{
    if (i >= j)
        return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}
void LowerTri::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    LowerTri lm(d);

    int x;
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i, j, x);
        }
    }

    cout << "Diagonal Matrix:" << endl;
    lm.Display();

    return 0;
}