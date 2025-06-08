#include <stdio.h>

struct Complex 
{
    float real;
    float imag;
};

struct Complex add(struct Complex c1, struct Complex c2) 
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;   

}

void multiply(struct Complex *c1, struct Complex *c2) 
{
    float real = c1->real * c2->real - c1->imag * c2->imag;
    float imag = c1->real * c2->imag + c1->imag * c2->real;
    c1->real = real;
    c1->imag = imag;
}

void display(struct Complex c) 
{
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

int main() 
{
    struct Complex c1, c2, result;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add complex numbers\n");
        printf("2. Multiply complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter real and imaginary parts of first complex number: ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter real and imaginary parts of second complex number: ");
                scanf("%f %f", &c2.real, &c2.imag);   

                result = add(c1, c2);
                printf("Sum: ");
                display(result);
                break;
            case 2:
                printf("Enter real and imaginary parts of first complex number: ");
                scanf("%f %f", &c1.real, &c1.imag);
                printf("Enter real and imaginary parts of second complex number: ");
                scanf("%f %f", &c2.real, &c2.imag);   

                multiply(&c1, &c2);
                printf("Product: ");
                display(c1);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
