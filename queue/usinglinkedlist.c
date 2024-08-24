#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Define a structure for the queue
struct Queue {
    Node* front;
    Node* rear;
};

typedef struct Queue Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (add) an element to the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
//
// Function to dequeue (remove) an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("|%d|", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int option,val,item;
    do{
    	printf("1. Enqueue: ");
    	printf("2. Dequeue: ");
    	printf("3. Display: ");
    	printf("---Choose:");
    	scanf("%d",&option);
    	switch(option){
    		case 1:
    			printf("\n Enter the value:");
    			scanf("%d",&val);
    			enqueue(queue, val);
    			break;
    		case 2:
    			item = dequeue(queue);
                printf("Dequeued item: %d\n", item);
				break;
    		case 3:
			    displayQueue(queue);
				break;	
		}
	}while(option!=4);
    return 0;
}


