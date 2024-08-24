#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit() function

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the stack structurenfax
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int evaluatePostfix(char postfix[]);

int main() {
    char postfix[MAX_SIZE];

    // Get postfix expression from the user
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);

    // Display the result
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}

// Function to push an item to the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    stack.top = -1; // Initialize stack top

    int i = 0;

    while (postfix[i] != '\0') {
        // If the scanned character is an operand, push it to the stack
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        }
        // If the scanned character is an operator, pop two operands from the stack, perform the operation, and push the result back
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    // The final result should be at the top of the stack
    return pop(&stack);

}

