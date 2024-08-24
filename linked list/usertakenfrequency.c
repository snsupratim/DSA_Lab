// calculating frequency:

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
void insert(struct node**head,int values){
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
void freq(struct node* head){
	while(head!=NULL){
		int value=head->data;
		int frequency=0;
		
		struct node* current=head;
		while(current!=NULL){
			if(current->data == value){
				frequency++;
			}
			current=current->link;
		}
		printf("value %d appears %d times\n",value,frequency);
		head=head->link;
	}
}
int main(){
	struct node *head=NULL;
	int n,value,i;
	
	printf("enter the number of elements=");
	scanf("%d",&n);
	
	printf("enter the elements= \n");
	for(i=0;i<n;i++){
		scanf("%d",&value);
		insert(&head,value);
	}
	printf("frequency of values in the list are: \n");
	freq(head);
	
		while(head!=NULL){
		struct node*temp=head;
		head=head->link;
		free(temp);
	}
	
	return 0;
}
