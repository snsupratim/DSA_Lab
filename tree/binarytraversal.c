#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *newNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node * insertNode(struct node *t, int data){
    if(t==NULL)
     {
     	 t=newNode(data);
     	 return t;
	 }
	if(data==t->data)
	  {
	  	printf("duplicate");
	  	return t;
	  }
	else if(data < t->data)
        t->left= insertNode(t->left,data);
       
    else 
      t->right= insertNode(t->right,data);
    return t;
    }



void inorder(struct node *t){
    if(t!=NULL){
          inorder(t->left);   
          printf("%d ->", t->data);
          inorder(t->right);  
        }
    
}
void preorder(struct node *t){
    if(t!=NULL){
    	  printf("%d ->", t->data);
          preorder(t->left);   
          preorder(t->right);  
        }
    
}
void postorder(struct node *t){
    if(t!=NULL){
    	  postorder(t->left);   
          postorder(t->right);  
          printf("%d ->", t->data);
        }
    
}
struct node* findsmallest(struct node* t){
	if(t==NULL||t->left==NULL){
		return t;
	}
	else{
		return findsmallest(t->left);
	}
}
struct node* findlargest(struct node* t){
	if(t==NULL||t->right==NULL){
		return t;
	}
	else{
		return findlargest(t->right);
	}
}

int main(){
    int step, data;
    struct node *root = NULL;
    int i,node;
    while(1){
        printf("1. Insert element\n");
        printf("2. Print tree inorder\n");
        printf("3. Print tree preorder\n");
        printf("4. Print tree postorder\n");
        printf("5. Printsmallest element:\n");
        printf("6. Print largest element:\n");
        printf("7. Exit\n");
        printf("Enter choice:");
        scanf("%d",&step);
        switch(step){
            case 1: 
			printf("enter number of node:");
			scanf("%d",&node);
			printf("enter element to be inserted\n");
			for(i=0;i<node;i++)
			{
                scanf("%d",&data);
                root=insertNode(root,data);
            }
                break;
            case 2:inorder(root); 
                printf("\n");
                break;
            case 3:preorder(root); 
                printf("\n");
                break;    
            case 4:postorder(root); 
                printf("\n");
                break; 
			case 5:
			root=findsmallest(root);
			printf("smallest element is %d \n",root->data);
			break;
			case 6:
			root=findlargest(root);
			printf("largest element is %d \n ",root->data);
			break;	   
            case 7: exit(0);    
        }
    }
    return 0;
}
