//Queue implementation using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue 
{
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) 
{
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
    } 
    else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Element inserted successfully\n");
}

void dequeue(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Element deleted: %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }
    free(temp);
}

void display(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    Queue q;
    initQueue(&q);
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
            {
                int data;
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            }
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
