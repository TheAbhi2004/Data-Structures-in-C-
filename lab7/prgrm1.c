//Queue implementation using array
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue() 
{
    int data;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    if (rear == MAX_SIZE - 1) 
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    queue[++rear] = data;
    printf("Element inserted successfully\n");
}

void dequeue() 
{
    if (front == -1) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    if (front == rear) 
    {
        front = -1;
        rear = -1;
    } 
    else 
    {
        front++;
    }
}

void display() 
{
    if (front == -1) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice;
    while (1) 
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
