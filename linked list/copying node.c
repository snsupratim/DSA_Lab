#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to copy elements from source list to destination list
void copyLinkedList(struct Node* sourceList, struct Node** destinationList) {
    // Initialize pointers for source and destination lists
    struct Node* sourceNode = sourceList;
    struct Node* destinationNode = NULL;
    
    // Iterate through the source list
    while (sourceNode != NULL) {
        // Create a new node with the same data as the source node
        struct Node* newNode = createNode(sourceNode->data);
        
        // If the destination list is empty, set the new node as the head
        if (*destinationList == NULL) {
            *destinationList = newNode;
            destinationNode = newNode;
        } else {
            // Otherwise, link the new node to the current destination node
            destinationNode->next = newNode;
            destinationNode = newNode;
        }
        
        // Move to the next node in the source list
        sourceNode = sourceNode->next;
    }
}

// Function to print a linked list
void printLinkedList(struct Node* list) {
    struct Node* currentNode = list;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample source linked list
    struct Node* sourceList = createNode(1);
    sourceList->next = createNode(2);
    sourceList->next->next = createNode(3);
    
    // Initialize the destination list as empty
    struct Node* destinationList = NULL;
    
    // Copy elements from source list to destination list
    copyLinkedList(sourceList, &destinationList);
    
    // Print the source and destination lists
    printf("Source List: ");
    printLinkedList(sourceList);
    
    printf("Destination List: ");
    printLinkedList(destinationList);
    
    return 0;
}

