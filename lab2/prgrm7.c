#include <stdio.h>
#include <stdlib.h>

// Function to search for an element in a dynamic array using binary search
int binarySearch(int *arr, int size, int target) 
{
    int low = 0;
    int high = size - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target) 
        {
            return mid; // Return the index of the found element
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
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

    printf("Enter the elements of the array in ascending order: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

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
