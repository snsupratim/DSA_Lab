#include<stdio.h>
#include<stdlib.h>

struct term{
	int coefficient;
	int exponent;
	struct term* link;
};

struct term* createterm(int coef,int exp){
	struct term* new=(struct term*)malloc(sizeof(struct term));
	if(new==NULL){
		printf("memory allocation failed:");
	}
	new->coefficient=coef;
	new->exponent=exp;
	new->link=NULL;
	return new;
}

void addtoploy(struct term** polynomial,int coef,int exp){
	struct term* newterm= createterm(coef,exp);
	if(*polynomial==NULL){
		*polynomial=newterm;
	}
	else{
		struct term* current=*polynomial;
		while(current->link != NULL){
			current=current->link;
		}
		current->link=newterm;
	}
}

void display(struct term* poly){
	int remainder,count=0;
	if(poly==NULL){
		printf("0...\n");
	}
	else{
		while(poly!=NULL){
			printf("%dx^%d ",poly->coefficient,poly->exponent);
			count++;
			remainder=count%2;
			if(poly->link !=NULL && remainder!=0){
				printf(" - ");
			}
			else if(poly->link !=NULL && remainder == 0){
				printf(" + ");
			}
			poly=poly->link;
		}
		
	}
}

int main(){
	struct term* poly=NULL;
	int terms;
	int coef,exp;
	
	printf("enter the number of terms (coefficent,exponent): ");
	scanf("%d",&terms);
	
	printf("enter the terms into the ploynomial: ");
	int i;
	for(i=0;i<terms;i++){
		scanf("%d %d",&coef,&exp);
		addtoploy(&poly,coef,exp);
	}
	
	printf("polynomial is: ");
	display(poly);
	
	return 0;
}
