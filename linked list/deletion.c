 #include<stdio.h>
 #include<stdlib.h>
 struct node{
 	int data;
 	struct node* link;
 };
struct node * deletefirst(struct node*head){
    struct node*ptr=head;
    head=head->link;
    free(ptr);
    return head;
}

struct node * deleteindex(struct node*head,int index){
    struct node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->link;
        i++;
    }
    struct node * q = p->link;
    p->link=q->link;
    free(q);
    return head;
}
struct node * deleteend(struct node*head){
    struct node*p=head;
     struct node * q = p->link;
    while(q->link!=NULL){
        p=p->link;
        q=q->link;
    }
   p->link=NULL;
    free(q);
    return head;
}
 void traversal(struct node* ptr){
    while(ptr!=NULL){
    printf("|%d|link|->",ptr->data);
    ptr=ptr->link;
    }
    printf("NULL");
}
 int main(){
 	int option;
 	struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    // allocated in heap through dynamic memory allocations:
    head= (struct node *)malloc(sizeof(struct node));
    second= (struct node *)malloc(sizeof(struct node));
    third= (struct node *)malloc(sizeof(struct node));
    fourth= (struct node *)malloc(sizeof(struct node));
    //linking:
    head->data=7;
    head->link=second;

    second->data=11;
    second->link=third;

    third->data=66;
    third->link=fourth;

    fourth->data=69;
    fourth->link=NULL;
    traversal(head);
    do{
    	printf("\n Choose an option: ");
    	printf("\n 1. Delete at Beginning: ");
    	printf("\n 2. Delete at index: ");
    	printf("\n 3. Delete at last: ");
    	printf("\n Enter your choices: ");
    	scanf("%d",&option);
    	switch(option)
		{
    		case 1: 
    		    head=deletefirst(head);
    		    traversal(head);
    		    break;
    		case 2:
    			head=deleteindex(head,2);
    			 traversal(head);
    			break;
    		case 3:
			    head=deleteend(head);
			    traversal(head);
				break;
		}
	}while(option!=4);
	
    

 	return 0;
 }
