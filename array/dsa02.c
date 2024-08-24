#include <stdio.h>

void deleteAtBeginning(int arr[], int *size) {
	int i;
    if (*size <= 0) {
        printf("Array is empty\n");
        return;
    }

    for ( i = 0; i < *size-1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteAtEnd(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty\n");
        return;
    }

    (*size)--;
}

void deleteAtPosition(int arr[], int *size, int position) {
	int i;
    if (*size <= 0 || position < 0 || position >= *size) {
        printf("Invalid position or array is empty\n");
        return;
    }

    for ( i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100];
    int size = 0;
    int choice, position;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose an option:\n");
    printf("1. Delete at the beginning\n");
    printf("2. Delete at the end\n");
    printf("3. Delete at any position\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteAtBeginning(arr, &size);
            break;
        case 2:
            deleteAtEnd(arr, &size);
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(arr, &size, position);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Array after deletion:\n");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

