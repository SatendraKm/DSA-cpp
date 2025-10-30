/*
╭──────────────────────────────────────────────────────────────────────────────╮
│                          ● Sparse Matrix ●                                   │
│                                                                              │
│                           • using c •                                        │
╰──────────────────────────────────────────────────────────────────────────────╯

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
    };
    struct Sparse
    {
    int m;
    int n;
    int num;
    struct Element *ele;
    };
    void create(struct Sparse *s)
    {
        printf("Enter the Dimenstions: ");
        scanf("%d%d", &s->m, &s->n);
        printf("Number of non-zeros ");
        scanf("%d", &s->num);
        s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
        printf("Enter all non-zeros Elements: ");
        for (int i = 0; i < s->num; i++)
        {
            scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
            }
}
void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
                }
                else
                {
                    printf("0 ");
                    }
                    }
                    printf("\n");
                    }
                    }
                    struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
                    {
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
        {
            sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].i > s2->ele[j].i)
        {
            sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                if (s1->ele[i].j < s2->ele[j].j)
                {
                    sum->ele[k++] = s1->ele[i++];
                    }
                    else if (s1->ele[i].j > s2->ele[j].j)
                    {
                sum->ele[k++] = s2->ele[j++];
                }
                else
                {
                    sum->ele[k] = s1->ele[i];
                    sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
                    }
                    }
                    }
                    for (; i < s1->num; i++)
                    {
                        sum->ele[k++] = s1->ele[i];
                        }
                        for (; j < s2->num; j++)
                        {
                            sum->ele[k++] = s2->ele[j];
                            }
                            sum->m = s1->m;
                            sum->n = s1->n;
                            sum->num = k;

                            return sum;
                            }

                            int main()
                            {
                                struct Sparse s1, s2, *s3;
                                create(&s1);
                                create(&s2);
                                s3 = add(&s1, &s2);
                                printf("First Matrix: \n");
                                Display(s1);
                                printf("Second Matrix: \n");
                                Display(s2);
                                printf("Sum Matrix: \n");
                                Display(*s3);

    return 0;
}

*/

// ╭──────────────────────────────────────────────────────────────────────────────╮
// │                          ● Sparse Matrix ●                                   │
// │                                                                              │
// │                           • using c++ •                                      │
// ╰──────────────────────────────────────────────────────────────────────────────╯

#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num);
    ~Sparse();
    Sparse operator+(Sparse &s);
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
};

Sparse::Sparse(int m, int n, int num)
{
    this->m = m;
    this->n = n;
    this->num = num;
    ele = new Element[this->num];
}

Sparse::~Sparse()
{
    delete[] ele;
}

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    i = j = k = 0;
    if (m != s.m || n != s.n)
    {
        cout << "Dimensions of both the Matrix doesnt match";
        return Sparse(0, 0, 0);
    }

    Sparse *sum = new Sparse(m, n, num + s.num);
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
        {
            sum->ele[k++] = ele[i++];
        }

        else if (ele[i].i > s.ele[j].i)
        {
            sum->ele[k++] = s.ele[j++];
        }

        else
        {
            if (ele[i].j < s.ele[j].j)
            {
                sum->ele[k++] = ele[i++];
            }

            else if (ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[j++];
            }

            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for (; i < num; i++)
    {
        sum->ele[k++] = ele[i];
    }
    for (; j < s.num; j++)
    {
        sum->ele[k++] = s.ele[j];
    }
    sum->num = k;
    return *sum;
}

istream &operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements: " << endl;
    for (int i = 0; i < s.num; i++)
    {
        is >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

ostream &operator<<(ostream &os, Sparse &s)
{
    int k = 0;
    cout << "The sparse matrix is: " << endl;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j)
            {
                os << s.ele[k++].x << " ";
            }
            else
            {
                os << "0 ";
            }
        }
        os << endl;
    }
    return os;
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    cin >> s1;
    cin >> s2;

    Sparse sum = s1 + s2;

    cout << "First Matrix:" << endl
         << s1;
    cout << "Second Matrix:" << endl
         << s2;
    cout << "Sum Matrix:" << endl
         << sum;

    return 0;
}