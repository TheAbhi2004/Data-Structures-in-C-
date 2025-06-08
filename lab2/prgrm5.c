#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort a dynamic array using bubble sort
void bubble_sort(int* arr, int size) 
{
    int i, j;
    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print a dynamic array
void print_array(int* arr, int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int size;
    printf("Enter the size of the dynamic array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bubble_sort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, size);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
