#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

        // Allocate memory for the left and right subarrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory for L and R
    free(L);
    free(R);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j < high; j++) 
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) 
        {
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot element with the element at index i+1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int n,ch;

    // Taking input from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    } 
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch) 
    {
    	case 1:
    	// Insertion Sort
    	int *arr1 = (int *)malloc(n * sizeof(int));
    	for (int i = 0; i < n; i++) 
    	arr1[i] = arr[i];
    	insertionSort(arr1, n);
    	printf("Sorted array using Insertion Sort: ");
    	printArray(arr1, n);
    	free(arr1); // Free the allocated memory
    	break;
    	
        case 2:
    	// Selection Sort
    	int *arr2 = (int *)malloc(n * sizeof(int));
    	for (int i = 0; i < n; i++) 
    	arr2[i] = arr[i];
    	selectionSort(arr2, n);
    	printf("Sorted array using Selection Sort: ");
    	printArray(arr2, n);
    	free(arr2); // Free the allocated memory
    	break;
	
	case 3:
    	// Merge Sort
    	int *arr3 = (int *)malloc(n * sizeof(int));
    	for (int i = 0; i < n; i++) 
    	arr3[i] = arr[i];
    	mergeSort(arr3, 0, n - 1);
    	printf("Sorted array using Merge Sort: ");
    	printArray(arr3, n);
    	free(arr3); // Free the allocated memory
    	break;
	
	case 4:
    	// Quick Sort
    	int *arr4 = (int *)malloc(n * sizeof(int));
    	for (int i = 0; i < n; i++) 
    	arr4[i] = arr[i];
    	quickSort(arr4, 0, n - 1);
    	printf("Sorted array using Quick Sort: ");
    	printArray(arr4, n);
    	free(arr4); // Free the allocated memory
    	break;
	
	case 5:
    	// Bubble Sort
    	int *arr5 = (int *)malloc(n * sizeof(int));
    	for (int i = 0; i < n; i++) 
    	arr5[i] = arr[i];
    	bubbleSort(arr5, n);
    	printf("Sorted array using Bubble Sort: ");
    	printArray(arr5, n);
    	free(arr5); // Free the allocated memory

    	free(arr); // Free the original array memory
    	break; 
    	default:
    	printf("Wrong choice:");
    	return 0;
    }
}
