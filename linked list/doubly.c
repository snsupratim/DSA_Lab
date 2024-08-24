#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};

void creation(struct node** head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->prev=NULL;
	new->next=NULL;
	if(*head==NULL){
		*head=new;
	}
	else{
		struct node* ptr=*head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=new;
		new->prev=ptr;
		new->next=NULL;
	}
}

struct node* insertfirst(struct node* head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	head->prev=new;
	new->next=head;
	new->prev=NULL;
	head=new;
	return head;
}
struct node* insertend(struct node* head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	struct node* ptr2=head;
	while(ptr2->next!=NULL){
		ptr2=ptr2->next;
	}
	ptr2->next=new;
	new->prev=ptr2;
	new->next=NULL;
	return head;
}

struct node* insertbefore(struct node* head,int data){
	int val;
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	printf("enter the value ,of before node to be entered:");
	scanf("%d",&val);
	struct node* ptr3=head;
	while(ptr3->data!=val){
		ptr3=ptr3->next;
	}
	new->next=ptr3;
	new->prev=ptr3->prev;
	ptr3->prev->next=new;
	return head;
}

struct node* insertafter(struct node* head,int data){
	int val;
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	printf("enter the value ,of after node to be entered:");
	scanf("%d",&val);
	struct node* ptr4=head;
	while(ptr4->data!=val){
		ptr4=ptr4->next;
	}
	new->next=ptr4->next;
	ptr4->next=new;
	new->prev=ptr4;
	ptr4->next->prev=new;
	return head;
}

struct node* deletefirst(struct node* head){
	struct node* ptr5=head;
	head=head->next;
	head->prev=NULL;
	free(ptr5);
	return head;
}

struct node* deleteend(struct node* head){
	struct node* ptr5=head;
	while(ptr5->next!=NULL){
		ptr5=ptr5->next;
	}
    ptr5->prev->next=NULL;
	free(ptr5);
	return head;
}

struct node* deletebefore(struct node* head){
	int val;
	printf("enter the value ,of before node to be entered:");
	scanf("%d",&val);
	struct node* ptr6=head;
	while(ptr6->data!=val){
		ptr6=ptr6->next;
	}
	struct node* temp=ptr6->prev;
	if(temp==head){
		head=deletefirst(head);
	}
	else{
		ptr6->prev=temp->prev;
		temp->prev->next=ptr6;
	}
	free(temp);
	return head;
	
}

struct node* deleteafter(struct node* head){
	int val;
	printf("enter the value ,of after node to be entered:");
	scanf("%d",&val);
	struct node* ptr7=head;
	while(ptr7->data!=val){
		ptr7=ptr7->next;
	}
	struct node* temp=ptr7->next;
	if(temp->next==NULL){
		head=deleteend(head);
	}
	else{
		ptr7->next=temp->next;
		temp->next->prev=ptr7;
	}
	free(temp);
	return head;
	
	
}
void traversal(struct node* head){
	struct node* ptr1=head;
	while(ptr1!=NULL){
		printf("|prev|%d|next|->",ptr1->data);
		ptr1=ptr1->next;
	}
	printf("NULL \n");
}

int main(){
	int node,value,i;
	int choice,data;
	struct node* head=NULL;
	
	printf("enter number of node:\n");
	scanf("%d",&node);
	printf("enter values:\n");
	for(i=0;i<node;i++){
		scanf("%d \n",&value);
		creation(&head,value);
	}
		traversal(head);
	printf("1.Insertfirst:\n");
	printf("2.Insertend:\n");
	printf("3.Insertbefore:\n");
	printf("4.Insertafter:\n");
	printf("5.Deletefirst:\n");
	printf("6.Deleteend:\n");
	printf("7.Deletebefore:\n");
	printf("8.Deleteafter:\n");
	do{
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter the  data to enter:");
				scanf("%d",&data);
				head=insertfirst(head,data);
				traversal(head);
				break;
			case 2:
				printf("enter the  data to enter:");
				scanf("%d",&data);
			    head=insertend(head,data);
				traversal(head);
				break;	
			case 3:
			    printf("enter the  data to enter:");
				scanf("%d",&data);
			    head=insertbefore(head,data);
				traversal(head);
				break;
			case 4:
				printf("enter the  data to enter:");
				scanf("%d",&data);
			    head=insertafter(head,data);
				traversal(head);
				break;
			case 5:
			    head=deletefirst(head);
			    traversal(head);
				break;
			case 6:
				head=deleteend(head);
			    traversal(head);
				break;
			case 7:
			    head=deletebefore(head);
				traversal(head);
				break;
			case 8:
			    head=deleteafter(head);
				traversal(head);
				break;					
		}
	}while(choice!=9);

	return 0;
}
