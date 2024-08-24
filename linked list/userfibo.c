// maintain fiobonacci series:

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
void fibonacci(struct node**head,int range){
	int a=0,b=1,c;
	int i;
	for(i=0;i<range;i++){
		insert(head,a);
		c=a+b;
		a=b;
		b=c;
	}
}
void display(struct node* ptr){
    while(ptr!=NULL){
    printf("|%d|link|-> ",ptr->data);
    ptr=ptr->link;
    }
    printf("NULL");
}
int main(){
	struct node *head=NULL;
	int n,value,i;
	
	printf("enter the number of elements=");
	scanf("%d",&n);
	
	fibonacci(&head,n);
	
	display(head);
	return 0;
}
