#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 100

struct stack{
	int top;
	char items[max];
};
void push(struct stack* stack,char item){
	if(stack->top==max-1){
		printf("overflow");
	}
	stack->items[++stack->top]=item;
}

char pop(struct stack* stack){
	if(stack->top==-1){
		printf("underflow");
	}
	return stack->items[stack->top--];
}
int isoperator(char ch){
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch=='%');
}
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/'|| ch=='%')
        return 1;
    else
        return 0;
}

void intopost(char infix[],char postfix[]){
	struct stack stack;
	stack.top=-1;
	int i,j;
	i=j=0;
	
	while(infix[i]!='\0'){
		if(infix[i]>='a'&&infix[i]<='z' || infix[i]>='A'&&infix[i]<='Z'){
			postfix[j++]=infix[i++];
		}
		else if(infix[i]=='('){
			push(&stack,infix[i++]);
		}
		else if (infix[i]==')'){
			while(stack.top!=-1 && stack.items[stack.top] != '('){
				postfix[j++]=pop(&stack);
			}
			if(stack.top==-1){
				printf("invalid expression");
			}
			pop(&stack);
			i++;
		}
		else if(isoperator(infix[i])){
			while (stack.top != -1 && stack.items[stack.top] != '(' && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator to the stack
            push(&stack, infix[i++]);
		}
		 else {
            printf("Invalid expression: Invalid character '%c'\n", infix[i]);
            exit(EXIT_FAILURE);
        }
	}
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

int main(){
	char infix[max],postfix[max];
	
	printf("enter the infix expression: ");
	scanf("%s",infix);
	
	intopost(infix,postfix);
	
	printf("The postfix expression is: %s ",postfix);
	
	return 0;
}
