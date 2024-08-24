#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Get infix expression from the user
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to push an item to the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch='%');
}

// Function to get the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/'||ch='%')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1; // Initialize stack top

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        // If the scanned character is an operand, add it to the output
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i++];
        }
        // If the scanned character is an '(', push it to the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        }
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (infix[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1) {
                printf("Invalid expression: Unmatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            pop(&stack); // Pop '(' from the stack
            i++;
        }
        // If the scanned character is an operator
        else if (isOperator(infix[i])) {
            // Pop operators from the stack until the stack is empty or the top element is '(' or has lower precedence
            while (stack.top != -1 && stack.items[stack.top] != '(' && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator to the stack
            push(&stack, infix[i++]);
        }
        // Invalid character in the expression
        else {
            printf("Invalid expression: Invalid character '%c'\n", infix[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Pop remaining operators from the stack and add to the output
    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression: Unmatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

