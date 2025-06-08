#include <stdio.h>
#include <stdlib.h>

typedef struct Stack 
{
    int *elements;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) 
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->elements = (int*) malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) 
{
    return stack->top == -1;
}

int isFull(Stack* stack) 
{
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int element) 
{
    if (isFull(stack)) 
    {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack->elements[++stack->top] = element;
}

int pop(Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->elements[stack->top--];
}

void printStack(Stack* stack) 
{
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) 
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

void reverseStack(Stack* stack) 
{
    int start = 0;
    int end = stack->top;
    while (start < end) 
    {
        int temp = stack->elements[start];
        stack->elements[start] = stack->elements[end];
        stack->elements[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    Stack* stack = createStack(capacity);

    printf("Enter %d elements:\n", capacity);
    for (int i = 0; i < capacity; i++) 
    {
        int element;
        scanf("%d", &element);
        push(stack, element);
    }

    int choice;
    while (1) 
    {
        printf("Stack operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                int element;
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(stack, element);
                break;
            case 2:
                int popped = pop(stack);
                printf("Popped: %d\n", popped);
                break;
            case 3:
                printStack(stack);
                break;
            case 4:
                reverseStack(stack);
                printStack(stack);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
