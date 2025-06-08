#include <stdio.h>
#include <stdlib.h> 

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL, *last = NULL;

void create(int x) 
{
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL) 
    {
        head = tmp;
        last = tmp;
    } 
    else 
    {
        last->next = tmp;
        last = tmp;
    }
}

void display() 
{
    struct node *P = head;
    if (head == NULL) 
    {
        printf("The Linked list is Empty\n");
    } else
     {
        while (P != NULL)
        {
            printf("%d\t", P->data);
            P = P->next;
        }
        printf("\n");
    }
}
int main() 
{
    int m, n, i;
    printf("Enter the Number of Nodes You need : \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) 
    {
        printf("Enter the value of node %d: \n", i);
        scanf("%d", &m);
        create(m);
    }
    printf("Linked List after traversing:\n");
    display();
}
    
