#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a Circular Queue
struct CircularQueue {
    struct Node *front, *rear;
};

// Function prototypes
void CENQUE(struct CircularQueue* cq, int element);
void CDELQUE(struct CircularQueue* cq);
void CDISPLAY(struct CircularQueue cq);
int isEmpty(struct CircularQueue cq);

// Function to insert an element in the Circular QUEUE
void CENQUE(struct CircularQueue* cq, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(*cq)) {
        cq->front = cq->rear = newNode;
        cq->rear->next = cq->front; // Linking the rear to front for circularity
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
        cq->rear->next = cq->front; // Linking the rear to front for circularity
    }

    printf("%d enqueued to the queue.\n", element);
}

// Function to delete an element from the Circular QUEUE
void CDELQUE(struct CircularQueue* cq) {
    if (isEmpty(*cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = cq->front;

    if (cq->front == cq->rear) {
        // If there's only one element in the queue
        cq->front = cq->rear = NULL;
    } else {
        cq->front = cq->front->next;
        cq->rear->next = cq->front; // Linking the rear to front for circularity
    }

    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}

// Function to display elements of the Circular QUEUE
void CDISPLAY(struct CircularQueue cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = cq.front;
    printf("Elements in the Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != cq.front);

    printf("\n");
}

// Function to check if the Circular Queue is empty
int isEmpty(struct CircularQueue cq) {
    return (cq.front == NULL && cq.rear == NULL);
}

// Main function with menu
int main() {
    struct CircularQueue cq;
    cq.front = cq.rear = NULL;

    int choice, element;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                CENQUE(&cq, element);
                break;
            case 2:
                CDELQUE(&cq);
                break;
            case 3:
                CDISPLAY(cq);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

