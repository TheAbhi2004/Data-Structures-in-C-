#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* arr, int size) 
{
    int* temp = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
    {
        temp[i] = arr[size - i - 1];
    }
    for (int i = 0; i < size; i++) 
    {
        arr[i] = temp[i];
    }
    free(temp);
}

void printArray(int* arr, int size) 
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

    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(arr, size);

    reverseArray(arr, size);

    printf("Reversed Array: ");
    printArray(arr, size);

    free(arr);

    return 0;
}
