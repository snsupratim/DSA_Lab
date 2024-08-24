#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* link;
};
 struct node *head;

 void push ()
 {
 int val;
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("not able to push the element");
 }
 else
 {
 printf("Enter the value");
 scanf("%d",&val);
 if(head==NULL)
 {
 ptr->val = val;
 ptr -> link = NULL;
 head=ptr;
 }
 else
 {
 ptr->val = val;
 ptr->link = head;
 head=ptr;

 }
 printf("Item pushed");

 }
 }
 int pop()
 {
 int item;
 struct node *ptr;

 if (head == NULL)
 {
 printf("Underflow");
 }
 else
 {
 item = head->val;
 ptr = head;
 head = head->link;
 free(ptr);
 printf("Item popped");
return item;
 }
 }
 void display()
 {
 int i;
 struct node *ptr;
 ptr=head;
 if(ptr == NULL)
 {
 printf("Stack is empty\n");
 }
 else
 {
 printf("Printing Stack elements \n");
 while(ptr!=NULL)
 {
 printf("%d\n",ptr->val);
 ptr = ptr->link;
 }
 }
 }
int main(){
	
	 int choice,item;
 
 do{
 printf("\n\nChose one from the below options...\n");
 printf("\n1.Push\n2.Pop\n3.Show");
 printf("\n Enter your choice \n");
scanf("%d",&choice);
 switch(choice)
 {
 case 1:
         push(head);
           break;
 case 2:
       item=pop(head);
       if(item!=-1){
       	printf("\n popped element is %d",item);
	   }
      break;
 case 3:
     display(head);
     break;
 }
	
}while(choice != 4);
     return 0;
}
