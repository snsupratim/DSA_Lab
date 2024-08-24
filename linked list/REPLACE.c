#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};
struct node * creation(int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL){
		printf("invalid!");
		exit(1);
	}
	new->data=data;
	new->link=NULL;
	return new;
}
void replace(struct node* head,int olddata,int newdata){
    struct node* ptr=head;
    while(ptr!=NULL){
        if(ptr->data==olddata){
            ptr->data=newdata;
            return;
        }
        ptr=ptr->link;
    }
    printf("%d is not found at the linked list.",olddata);
}

void printlist(struct node*head){
	struct node*current=head;
	while(current!=NULL){
		printf("|%d|link|->",current->data);
		current=current->link;
	}
	printf("NULL");
}
int main(){
	struct node* head=creation(1);
	head->link=creation(2);
	head->link->link=creation(3);
	head->link->link->link=creation(4);
	

	printf("\n Original linked list:\n");
	printlist(head);
	printf("\n replacing 2 with 4->\n");
	printf("\n Updated Linked List:\n");
	replace(head,2,4);
	printlist(head);
		
	while(head!=NULL){
		struct node*temp=head;
		head=head->link;
		free(temp);
	}
	
	return 0;
	
	
}
