
#include <stdio.h>
#include <stdlib.h> 

struct node 
{
    int val;
    struct node *next;
};

struct node *head = NULL, *last = NULL;

void create(int x) 
{
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->val = x;
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
            printf("%d\t", P->val);
            P = P->next;
        }
        printf("\n");
    }
}

void insert_beginning(int x)
{
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->val = x;
    tmp -> next = head;
    head = tmp;
}

void insert_last(int x)
{
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->val = x;
    tmp -> next= NULL;
    last -> next = tmp;
    last = tmp;
}

void insert_pos(int x, int pos)
{
    struct node *p = head, *tmp;
    int i;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp -> val = x;
    for(i = 1; i < (pos - 1); i++ )
    {
        p = p-> next;
    }
        tmp -> next = p -> next;
        p -> next = tmp;
    
}

void delete_beginning(int x)
{
    struct node* q = head;
    if(head == NULL)
    {
        printf("The Linked List is Empty");
    }
    else
    {
        head = head -> next;
        free(q);
    }
}

void delete_last(int x)
{
    struct node *q = head, *s;
    if( head == NULL )
    {
        printf("The Above Linked List is Empty");
    }
    else
    {
        while(q->next!=NULL)
        {
            s=q;
            q=q->next;
        } 
        s->next=NULL;
        free(s); 
        s=NULL;
    }
}

void delete_pos(int x, int pos)
{
    struct node *p = head, *q; int i =1;
    for(i = 1; i< (pos - 1);i++ )
    {
        p = p-> next;
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
    display();
    while(1)
    {
    printf("Do You want to \n 1. Insert \n 2. Delete \n 3.Quit\n 4. Display\n");
    int ch,z;
    printf("Enter Your Choice : \n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
            while(1)
            {
            printf("You want to \n 1. Insert at beginning \n 2. Insert at Last \n 3. Insert At Position \n 4. Quit\n");
            int C,z;
            printf("Enter Your Choice : \n");
            scanf("%d",&C);
            switch (C)
            {
                case 1:
                    printf("Enter the Value You want to insert at Beginning : \n");
                    scanf("%d",&z);
                    insert_beginning(z);
                    display();
                    break;
                case 2:
                    printf("Enter the Value You want to insert at Last : \n");
                    scanf("%d",&z);
                    insert_last(z);
                    display();
                    break;
                case 3:
                    int pos;
                    printf("Enter the Value of Node : \n");
                    scanf("%d",&z);
                    printf("Enter the Position at which you want to insert : \n");
                    scanf("%d",&pos);
                    insert_pos(z,pos);
                    display();
                    break;
                case 4:                                                         
                    exit(0);
            }
            }
        case 2:
            while(1)
            {
                printf("You want to \n 1. Delete at beginning \n 2. Delete at Last \n 3. Delete At Position \n 4. Quit\n");
                int C;
                printf("Enter Your Choice : \n");
                scanf("%d",&C);
                switch (C)
                {
                case 1:
                    printf("Enter the Value You want to delete at Beginning : \n");
                    scanf("%d",&z);
                    delete_beginning(z);
                    display();
                    break;
                case 2:
                    printf("Enter the Value You want to delete at last : \n");
                    scanf("%d",&z);
                    delete_last(z);
                    display();
                    break;
                case 3:
                    {
                    int pos; 
                    printf("Enter the value you want to delete at position:\n");
                    scanf("%d",&z);
                    printf("Enter the Position at which you want to delete : \n");
                    scanf("%d",&pos);
                    delete_pos(z,pos);
                    display();
                    }
                    break;
                case 4:
                    exit(0);
                }
            }
        case 3:
            exit(0);
        
    }
    }
    return 0;
}
