#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};

void creation(struct node** head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	if(*head==NULL){
		new->prev=NULL;
		new->data=data;
		new->next=*head;
		*head=new;
	}
	else{
		new->data=data;
		struct node* ptr=*head;
		while(ptr->next!= *head){
			ptr=ptr->next;
		}
		new->prev=ptr;
		ptr->next=new;
		new->next=*head; 
		
	}
}
void traversal(struct node* head){
	struct node* ptr1=head;
	while(ptr1->next!=head){
		printf("|prev|%d|next|->",ptr1->data);
		ptr1=ptr1->next;
	}
	printf("|prev|%d|next|->HEAD",ptr1->data);

}

int main(){
	struct node* head=NULL;
	int node,value,i;
	
	printf("enter number of nodes:");
	scanf("%d",&node);
	printf("enter the node element:");
	for(i=0;i<node;i++){
		scanf("%d",&value);
		creation(&head,value);
	}
	traversal(head);
	return 0;
}
