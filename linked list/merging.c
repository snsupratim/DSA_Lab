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

// Function to merge two sorted linked lists
struct Node* mergeLinkedLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node as the head of the merged list
    struct Node* mergedListHead = createNode(0);
    struct Node* mergedListTail = mergedListHead;
    
    // Initialize pointers for list1 and list2
    struct Node* current1 = list1;
    struct Node* current2 = list2;
    
    // Traverse both lists while they are not empty
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            // Add the current node from list1 to the merged list
            mergedListTail->next = current1;
            current1 = current1->next;
        } else {
            // Add the current node from list2 to the merged list
            mergedListTail->next = current2;
            current2 = current2->next;
        }
        
        // Move the merged list tail pointer
        mergedListTail = mergedListTail->next;
    }
    
    // If list1 is not empty, append the remaining nodes
    if (current1 != NULL) {
        mergedListTail->next = current1;
    }
    
    // If list2 is not empty, append the remaining nodes
    if (current2 != NULL) {
        mergedListTail->next = current2;
    }
    
    // Return the merged list (excluding the dummy head)
    return mergedListHead->next;
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
    // Create two sorted linked lists
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    
    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    
    // Merge the two lists
    struct Node* mergedList = mergeLinkedLists(list1, list2);
    
    // Print the merged list
    printf("Merged List: ");
    printLinkedList(mergedList);
    
    return 0;
}

