//?userdefine linked list for storing factorial

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	long factorial;
	struct node* link;
};
void create(struct node**head,int data){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->factorial=1;
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
long fact(int n){
	int i;
	if(n==0||n==1){
		return 1;
	}
	long result=1;
	for(i=2;i<=n;i++){
		result *= i;
	}
	return result;
}
void display(struct node* ptr){
    while(ptr!=NULL){
    printf("|%d|%ld|link|-> ",ptr->data,ptr->factorial);
    ptr=ptr->link;
    }
    printf("NULL");
}
int main(){
	struct node* head=NULL;
	int nodes,data,i;
	
	printf("Enter the number of nodes: ");
	scanf("%d",&nodes);
	printf("Enter the data into the nodes:\n");
	for(i=0;i<nodes;i++){
		scanf("%d",&data);
		create(&head,data);
	}
	struct node* current=head;
	while(current!=NULL){
		current->factorial=fact(current->data);
		current=current->link;
	}
	printf("The Linked List :\n");
	display(head);
	
	while(head!=NULL){
		struct node*temp=head;
		head=head->link;
		free(temp);
	}
	
	return 0;
}
