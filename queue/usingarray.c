#include<stdio.h>
#define size 10
int queue[size];
int front=-1,rear=-1;

void insert(){
	int num;
	printf("enter number to be inserted: ");
	scanf("%d",&num);
	if(rear==size-1){
		printf("overflow");
	}
	else if(front==-1 && rear==-1){
		front=rear=0;
	}
	else{
		rear++;
	}
	queue[rear]=num;
}

int delete(){
	int val;
	if (front==-1|| rear==-1){
		printf("underflow");
		return -1;
	}
	else{
		val=queue[front];
		front++;
		if(front>rear){
			front=rear=-1;
		}
		return val;
	}
}
int peek(){
	if(front==-1||front>rear){
		printf("queue is empty");
		return -1;
	}
	else{
		return queue[front];
	}
}
void display(){
	int i;
	printf("\n");
	if (front==-1 || front>rear){
		printf("queue is empty");
	}
	else{
		for(i=front;i<=rear;i++){
			printf("\t %d",queue[i]);
		}
	}
}


int main(){
	
	int option,val;
	do{
		printf("\n 1. for insert: \n");
		printf("2. for delete: \n");
		printf("3. for peek: \n");
		printf("4. for display: \n");
		printf("enter your choice: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert();
				break;
			case 2:
			val=delete();
			if(val!=-1){
				printf("\n deleted number is: %d",val);
			}
				break;
			case 3:
			val=peek();
			if(val!=-1){
				printf("first value is: %d",val);
			}
				break;
			case 4:
			display();
			break;	
				
			}	
		}while(option!=5);
		
		
	
	return 0;
}
