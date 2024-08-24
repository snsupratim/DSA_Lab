#include <stdio.h>

// Function to merge two sorted subarrays arr[low..mid] and arr[mid+1..high]
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1; // Size of the left subarray
    int n2 = high - mid;   // Size of the right subarray
	int s; 

    // Create temporary arrays to hold the left and right subarrays
    int left[n1], right[n2];

    // Copy data to temporary arrays left[] and right[]
    for ( s = 0; s< n1; s++) {
        left[s] = arr[low + s];
    }
    for ( s = 0; s < n2; s++) {
        right[s] = arr[mid + 1 + s];
    }

    // Merge the two subarrays back into the original array arr[]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on the given array
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the middle point to divide the array into two halves
        int mid = low + (high - low) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original array: \n");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

