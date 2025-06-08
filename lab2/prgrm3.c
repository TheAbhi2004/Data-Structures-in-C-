#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int arr[], int size) 
{
    int i, j=0;

    for (i = 0; i < size-1; i++) 
    {
         if (arr[i]!=arr[i+1]) 
            {
                arr[j]=arr[i];
                j++;
            }
    }
    arr[j]=arr[size-1];
    size--;
}    

void printArray(int arr[],int size ) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(arr, size);

    removeDuplicates(arr, size);

    printf("Array after removing duplicates: ");
    printArray(arr,size);

    return 0;
}
