#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Number of terms? ");
    scanf("%d", &p->n);

    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < p->n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    printf("Polynomial: ");
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i < p.n - 1)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    struct Poly p1;
    create(&p1);
    display(p1);

    free(p1.terms);
    return 0;
}
