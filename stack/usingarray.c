#include<stdio.h>
#define size 10
int stack[size];
int top=-1;

void push(int stack[],int val){
	if(top==size-1){
		printf("overflow");
	}
	else{
		top=top+1;
		stack[top]=val;
	}
}

int pop(int stack[]){
	int val;
	if(top==-1){
		printf("underflowed");
	}
	else{
		val=stack[top];
		top--;
		return val;
	}
}
int peek(int stack[]){
	if(top==-1){
		printf("stack is empty");
	}
	else{
		return stack[top];
	}
}
void display(int stack[]){
	int i;
	for(i=top;i>=0;i--){
		printf("%d \n",stack[i]);
	}
	if(top==-1){
		printf("\n stack is empty");
	}
}

int main(){
	
	int option,val;
	do{
		printf(" \n 1. insrt an element: \n ");
		printf(" \n 2. delete an element: \n ");
		printf(" \n 3. peek an element: \n ");
		printf(" \n 4. show the stack: \n ");
		printf(" \n choose an option: \n ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("enter the value: ");
				scanf("%d",&val);
				push(stack,val);
				break;
			case 2:
			val=pop(stack);
			if(val!=-1){
				printf("\n the popped element is: %d",val);
			}	
			break;
			case 3:
				val=peek(stack);
					if(val!=-1){
				printf("\n the value stored in top is  is: %d",val);
			}	
			break;
			case 4:
			display(stack);
			break;	
		}
	}while(option!=5);
	
	return 0;
}
