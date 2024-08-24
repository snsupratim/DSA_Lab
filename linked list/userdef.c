#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
void create(struct node**head,int values){
	struct node* create=(struct node*)malloc(sizeof(struct node));
	create->data=values;
	create->link=NULL;
	
	if(*head==NULL){
		*head=create;
	}
	else{
		struct node* current=*head;
		while(current->link!=NULL){
			current=current->link;
		}
		current->link=create;
	}

}
struct node* insertfirst(struct node* head,int data){
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->link=head;
	ptr->data=data;
	return ptr;
	
}
void display(struct node* ptr){
    while(ptr!=NULL){
    printf("|%d|link|-> ",ptr->data);
    ptr=ptr->link;
    }
    printf("NULL");
}
int main(){
	int option;
	
    struct node *head=NULL;
	int n,value,i;
	int data;
	
	
	do{
		printf("\n 1. Create a List:");
		printf("\n 2. Insert at first into the  List:");
		printf("\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
//			creation of linked list
			case 1:
				printf("enter the number of elements=");
            	scanf("%d",&n);
	            printf("enter the elements= \n");
	          for(i=0;i<n;i++){
		      scanf("%d",&value);
	       	  create(&head,value);
	        }
	        display(head);
	         break;
//	       insert a ne node at beginning  
	        case 2:
	        	printf("\n enter data into new node: ");
	        	scanf("%d",&data);
	        	head=insertfirst(head,data);
	        	display(head);
	        	break; 
		}
		
	}while(option!=3);
	
	//freeing memory:
		while(head!=NULL){
		struct node*temp=head;
		head=head->link;
		free(temp);
	}
	
	return 0;
}
