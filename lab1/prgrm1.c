//Write a program to read two numbers and compare the numbers using function call by address 
#include <stdio.h>

void compare(int *num1, int *num2) 
{
    if (*num1 > *num2) 
    {
        printf("%d is greater than %d\n", *num1, *num2);
    } else if (*num1 < *num2) 
    {
        printf("%d is less than %d\n", *num1, *num2);
    } else   
    {
        printf("%d is equal to %d\n", *num1, *num2);   

    }
}

int main() 
{
    int n1, n2;

    printf("Enter the first number: ");
    scanf("%d", &n1);

    printf("Enter the second number: ");
    scanf("%d", &n2);

    compare(&n1, &n2);

    return 0;   

}
