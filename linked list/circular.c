#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

void creation(struct node** head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	if(*head==NULL){
		new->link=new;
	  *head=new;
}
	else{
		struct node* ptr1=*head;
		while(ptr1->link!= *head){
			ptr1=ptr1->link;
		}
		ptr1->link=new;
		new->link=*head;
	}  
}

struct node* insertfirst(struct node* head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	struct node* ptr3=head;
	while(ptr3->link!=head){
		ptr3=ptr3->link;
	}
	ptr3->link=new;
	new->link=head;
	head=new;
	return head;

}

struct node* insertend(struct node* head,int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	struct node* ptr5=head;
	while(ptr5->link!=head){
		ptr5=ptr5->link;
	}
	ptr5->link=new;
	new->link=head;
	return head;
}

struct node* deletefirst(struct node* head){
	struct node* ptr4=head;
	while(ptr4->link!=head){
		ptr4=ptr4->link;
	}
	ptr4->link=head->link;
	free(head);
	head=ptr4->link;
	return head;

}

struct node* deleteend(struct node* head){
	struct node* ptr6=head;
	struct node* preptr;
	while(ptr6->link!=head){
		preptr=ptr6;
		ptr6=ptr6->link;
	}
	preptr->link=ptr6->link;
	free(ptr6);
	return head;
}

void traversal(struct node* head){
	struct node* ptr2=head;
	while(ptr2->link!=head){
		printf("|%d|link|->",ptr2->data);
		ptr2=ptr2->link;
	}
	printf("|%d|link|->HEAD \n ",ptr2->data);
}


int main(){
	struct node* head=NULL;
	int node,value,i;
	int choice,data;
	
	printf("enter number of nodes:\n");
	scanf("%d",&node);
	printf("enter the element:\n");
	for(i=0;i<node;i++){
		scanf("%d",&value);
		creation(&head,value);
	}
	traversal(head);
	printf("1. insertfirst:\n");
	printf("3. insertend:\n");
	printf("2. deletefirst:\n");
	printf("4. deleteend:\n");
	do{
		printf("enter choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value to insrt at first:\n");
				scanf("%d",&data);
				head=insertfirst(head,data);
				traversal(head);
				break;
			case 2:
			    head=deletefirst(head);
				traversal(head);
				break;
			case 3:
				printf("enter value to insrt at first:\n");
				scanf("%d",&data);
			    head=insertend(head,data);
				traversal(head);
				break;
			case 4:
				 head=deleteend(head);
				traversal(head);
				break;
						
		}
	}while(choice!=5);
	
	return 0;
}
