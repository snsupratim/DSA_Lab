//?userdefine linked list for storing factorial

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data;
	struct node* link;
};
void create(struct node**head,int data){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->link=NULL;
	if(*head==NULL){
		*head=node;
	}
	else{
		struct node* current=*head;
		while(current->link!=NULL){
			current=current->link;
		}
		current->link=node;
	}	
}
void powfunction(struct node**head,int power){
	 int value;
	struct node* ptr=*head;
	while(ptr!=NULL){
		value=pow(ptr->data,power);
		printf("|%d|link|->",value);
		ptr=ptr->link;
	}
	printf("NULL");
}

void display(struct node* ptr){
    while(ptr!=NULL){
    printf("|%d|link|-> ",ptr->data);
    ptr=ptr->link;
    }
    printf("NULL");
}
int main(){
	struct node* head=NULL;
	int nodes,data,i;
	int p;
	
	printf("Enter the number of nodes: ");
	scanf("%d",&nodes);
	printf("Enter the data into the nodes:\n");
	for(i=0;i<nodes;i++){
		scanf("%d",&data);
		create(&head,data);
	}

	printf("The Linked List :\n");
	display(head);
	printf("\n Enter the power:");
	scanf("%d",&p);
	printf("Updated Linked List:\n");
	powfunction(&head,p);
//	
	while(head!=NULL){
		struct node*temp=head;
		head=head->link;
		free(temp);
	}
	
	return 0;
}
