 #include<stdio.h>
 #include<stdlib.h>
 struct node{
 	int data;
 	struct node* link;
 };
 struct node * insertfirst(struct node *head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->link=head;
    ptr->data=data;
    return ptr;
}

struct node * insertindex(struct node *head,int data,int index){
    struct node * ptr  = (struct node *)malloc(sizeof(struct node));
   struct node * p= head;
   int i=0;
   while(i!=index){
    p=p->link;
    i++;
   }
   ptr->data=data;
   ptr->link=p->link;
   p->link=ptr;
   return head;
}

struct node * insertend(struct node *head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p= head;
    while (p->link!=NULL)
    {
      p=p->link;
    }
    p->link=ptr;
    ptr->link=NULL;
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
    	printf("\n 1. Insert at Beginning: ");
    	printf("\n 2. Insert at a given position: ");
    	printf("\n 3. Insert at last: ");
    	printf("\n Enter your choices: ");
    	scanf("%d",&option);
    	switch(option)
		{
    		case 1: 
    		    head=insertfirst(head,9);
    		    traversal(head);
    		    break;
    		case 2:
    			head=insertindex(head,5,2);
    			 traversal(head);
    			break;
    		case 3:
			    head=insertend(head,3);
			    traversal(head);
				break;
		}
	}while(option!=4);
	
    

 	return 0;
 }
