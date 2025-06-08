#include <stdio.h>
#include <stdlib.h>

// Function to search for an element in a dynamic array
int searchElement(int *arr, int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = searchElement(arr, size, target);

    if (result != -1) 
    {
        printf("Element %d found at index %d\n", target, result);
    } else 
    {
        printf("Element %d not found in the array\n", target);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
