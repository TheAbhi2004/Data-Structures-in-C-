#include <stdio.h>

void mergeSortedArrays(int arr1[], int arr2[], int m, int n, int arr3[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) 
    {
        if (arr1[i] < arr2[j]) 
        {
            arr3[k++] = arr1[i++];
        } 
        else 
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < m) 
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n) 
    {
        arr3[k++] = arr2[j++];
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int m, n;

    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter elements of the first array (in sorted order): ");
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter elements of the second array (in sorted order): ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    int arr3[m + n];

    mergeSortedArrays(arr1, arr2, m, n, arr3);

    printf("Array 1: ");
    printArray(arr1, m);
    printf("Array 2: ");
    printArray(arr2, n);
    printf("Merged Array: ");
    printArray(arr3, m + n);

    return 0;
}
