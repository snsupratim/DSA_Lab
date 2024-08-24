#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1);
}

void CENQUE() {
    if (isFull()) {
        printf("Circular Queue is full. Cannot insert more elements.\n");
    } else {
        int item;
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        
        queue[rear] = item;
        printf("%d element has been inserted into the Circular Queue.\n");
    }
}

void CDELQUE() {
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot delete an element.\n");
    } else {
        int item = queue[front];
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        
        printf("%d has been deleted from the Circular Queue.\n", item);
    }
}

void CDISPLAY() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
    } else {
        int i = front;
        printf("Elements in the Circular Queue: ");
        
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        
        printf("\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element (CENQUE)\n");
        printf("2. Delete an element (CDELQUE)\n");
        printf("3. Display elements (CDISPLAY)\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                CENQUE();
                break;
            case 2:
                CDELQUE();
                break;
            case 3:
                CDISPLAY();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

