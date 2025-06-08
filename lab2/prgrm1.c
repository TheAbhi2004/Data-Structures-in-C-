#include <stdio.h>
#include<stdlib.h>

void insertion(int *arr, int element, int position,int n) 
{
        for (int i = n-1; i >= position; i--) 
        {
            arr[i + 1] = arr[i];
        }
        arr[position] = element;
        ++n;
}

void deletion(int *arr, int n, int position) 
{
        for (int i = position; i < n-1; i++) 
        {
            arr[i] = arr[i + 1];
        }
        n--;
}

int linearSearch(int *arr, int n, int element) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == element) 
        {
            return i;
        }
    }
    return -1;
}

void traverseArray(int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main() 
{
    int n = 0;
    int choice, element, position;

    while (1) 
    {
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter the  range:");
                scanf("%d",&n); 
                int *arr = (int *)malloc(n * sizeof(int));
                printf("Enter the elements in an array:");
                for(int i=0;i<n;i++) 
                {
                   scanf("%d",&arr[i]); 
                }   
                
                insertion(arr, element, position,n);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                printf("Enter the range:"); 
                scanf("%d",&n);
                int *arr = (int *)malloc(n * sizeof(int));
                printf("Enter the elements in an array:");
                for(int i=0;i<n;i++) 
                {
                   scanf("%d",&arr[i]); 
                }   
                deletion(arr, n, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                int *arr = (int *)malloc(n * sizeof(int));
                printf("Enter the elements in an array:");
                for(int i=0;i<n;i++) 
                {
                   scanf("%d",&arr[i]); 
                }   
                int result = linearSearch(arr, n, element);
                if (result != -1) 
                {
                    printf("Element found at position %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                int *arr = (int *)malloc(n * sizeof(int));
                traverseArray(arr, n);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
