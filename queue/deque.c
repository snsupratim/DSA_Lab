#include<stdio.h>
#include<conio.h>
#define max 10

int deque[max];
int left=-1;
int right=-1;

void input_deque(){
	int option;
	do{
		printf("1. insert at right:\n");
		printf("2. output from right:\n");
		printf("3. output from left:\n");
		printf("4. display:");
		printf("enter your choice:");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert_right();
				break;
			case 2:
			    delete_right();
				break;
			case 3:
			    delete_left();
			    break;
			case 4:
			   display();
			   break;		
		}
	}while(option!=5);
}

void output_deque(){
	int option;
	do{
		printf("1. insert at right:\n");
		printf("2. insert at left:\n");
		printf("3. output from left:\n");
		printf("4. display:");
		printf("enter your choice:");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert_right();
				break;
			case 2:
			    insert_left();
				break;
			case 3:
			    delete_left();
			    break;
			case 4:
			   display();
			   break;		
		}
	}while(option!=5);
}

void insert_right(){
	int val;
	printf("enter value to be inset:");
	scanf("%d",&val);
	if((left==0 && right==max-1)|| (left==right+1)){
		printf("overflow");
	}
	if(left==-1){
		left=0;
		right=0;
	}
	else{
		if(right==max-1){
			right=0;
		}
		else{
			right=right+1;
		}
	}
	deque[right]=val;
}

void insert_left(){
		int val;
	printf("enter value to be inset:");
	scanf("%d",&val);
	if((left==0 && right==max-1)||(left==right+1)){
		printf("overflowed");
	}
	if(left==-1){
		left=0;
		right=0;
	}
	else{
		if(left==0){
			left=max-1;
		}
		else{
			left--;
		}
	}
	deque[left]=val;
}

void delete_left(){
	if(left==-1){
		printf("underflow");
	}
	printf("deleted element is %d",deque[left]);
	if(left==right){
		left=-1;
		right=-1;
	}
	else{
		if(left==max-1){
			left=0;
		}
		else{
			left++;
		}
	}
}

void delete_right(){
	if(left==-1){
		printf("underflow");
	}
	printf("deleted element is %d",deque[right]);
	if(left==right){
		left=-1;
		right=-1;
	}
	else{
		if(right==0){
			right=max-1;
		}
		else{
			right--;
		}
	}
}

void display(){
	int front=left,rear=right;
	if(front==-1){
		printf("queue is empty");
	}
	printf("elements are:");
	if(front<=rear){
		while(front<=rear){
			printf("%d",deque[front]);
			front++;
		}
	}
	else{
		while(front<=max-1){
			printf("%d",deque[front]);
			front++;
		}
		front=0;
		while(front<=rear){
			printf("%d",deque[front]);
			front++;
		}
	}
	printf("\n");
}

int main(){
	int option;
	printf("1. Input restricted deque:\n");
	printf("2. Outut restircted deque: \n");
	printf("enter your option:");
	scanf("%d",&option);
	switch(option){
		case 1:
			input_deque();
			break;
		case 2:
		output_deque();
		break;	
	}
	return 0;
}

