#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node{
	int data;
	int priority;
	struct node* link;
};
struct node* head=NULL;

struct node* insert(struct node* head){
	int val,pri;
	struct node *ptr,*p;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("enter the value and priority: ");
	scanf("%d %d",&val,&pri);
	ptr->data=val;
	ptr->priority=pri;
	if(head==NULL||pri<head->priority){
		ptr->link=head;
		head=ptr;
	}
	else{
		p=head;
		while(p->link!=NULL && p->link->priority<=pri){
			p=p->link;
		}
		ptr->link=p->link;
		p->link=ptr;
	}
	return head;
}

struct node* delete(struct node* head){
	struct node* ptr;
	if(head==NULL){
		printf("underflow");
	}
	else{
		ptr=head;
		printf("deleted item is %d",ptr->data);
		head=head->link;
		free(ptr);
	}
	return head;
}

void display(struct node* head){
	struct node* ptr;
	ptr=head;
	if(head==NULL){
		printf("queue is empty");
	}
	else{
		printf("prioriry queue is:\n");
		while(ptr !=NULL){
			printf("|%d|prioriry=%d|link|->",ptr->data,ptr->priority);
			ptr=ptr->link;
		}
	}
}

int main(){
	
	int option;
	do{
		printf("1. insert: \n");
		printf("2. delete:\n");
		printf("3. display:\n");
		printf("enter your option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				head=insert(head);
				break;
			case 2:
			head=delete(head);
			break;
			case 3:
			display(head);
			break;	
		}
	}while(option!=4);
}
