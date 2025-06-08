#include <stdio.h>

void printPoly(int poly[], int n) 
{
    for (int i = n - 1; i >= 0; i--) 
    {
        if (poly[i] != 0) 
        {
            if (i != n - 1) 
            {
                printf(" + ");
            }
            if (i == 0) 
            {
                printf("%d", poly[i]);
            }
           else if (i == 1) 
            {
                printf("%dx", poly[i]);
            }
             else 
            {
                printf("%dx^%d", poly[i], i);
            }
        }
    }
    printf("\n");
}

void addPoly(int poly1[], int poly2[], int n) 
{
    int sum[n];
    for (int i = 0; i < n; i++) 
    {
        sum[i] = poly1[i] + poly2[i];
    }
    printf("Sum of the two polynomials: ");
    printPoly(sum, n);
}

int main() 
{
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    int poly1[n + 1];
    int poly2[n + 1];
    printf("Enter coefficients of the first polynomial:\n");
    for (int i = n; i >= 0; i--) 
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printf("Enter coefficients of the second polynomial:\n");
    for (int i = n; i >= 0; i--) 
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    printf("First polynomial: ");
    printPoly(poly1, n + 1);
    printf("Second polynomial: ");
    printPoly(poly2, n + 1);
    addPoly(poly1, poly2, n + 1);
    return 0;
}
