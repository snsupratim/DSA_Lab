#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
	int i,j,temp;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
//                swap(&arr[j], &arr[j + 1]);
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int n,i,j;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count[n];
    for ( i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the array
    for ( i = 0; i < n; i++) {
        for ( j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
                count[j]++;
            }
        }
    }

    // Delete all occurrences of elements that occur more than once
    int newSize = 0;
    for ( i = 0; i < n; i++) {
        if (count[i] == 0) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    // Resize the array
    n = newSize;

    // Sort the array
    bubbleSort(arr, n);

    // Display the final sorted array
    printf("Final sorted array after removing duplicates: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

