#include<stdio.h>
#include<stdlib.h>
void atfirst(int arr[],int *size){
int i;
	for(i=0;i<*size-1;i++){
		arr[i]=arr[i+1];
	}
	(*size)--;
}
void atlast(int arr[],int *size)
{	
	(*size)--;
}
void ataposition(int arr[],int *size,int position)
{
	int i;
	for(i=position;i<*size-1;i++){
		arr[i]=arr[i+1];
	}
	(*size)--;
}
void search(int arr[],int *size,int element)
{
	int i;
	for(i=0;i<*size;i++){
		if(element==arr[i])
		{
			printf(" \n the element is found at %d position",i);
			break;
		}
	}	
}
void replace(int arr[],int *size,int element,int number)
{
	int i;
	for(i=0;i<*size;i++){
		
		if(element==arr[i])
		{
			printf("the element is found at %d position",i);
			arr[i]=number;
			break;
		}	
	}	
}
int main(){
	int arr[100];
	int size=0;
	int i,position,option,element,number;
	printf("\nenter number of element= ");
	scanf("%d",&size);
	printf("\nenter the element= \n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n array is=\n");
		for(i=0;i<size;i++){
		printf("%d",arr[i]);
	}
    printf("\nchoose an option: \n");
    printf("1. delete at first:\n");
    printf("2. delete at last:\n");
    printf("3. delete at any position:\n");
    printf("4. search an element :\n");
    printf("5. replace an element :\n");
    scanf("%d",&option);
    switch(option)
	{
    	case 1: 
    	   atfirst(arr,&size);
    	   break;
    	case 2:
    		atlast(arr,&size);
    		break;
        case 3:
    		printf("enter the position= ");
            scanf("%d",&position);
    	    ataposition(arr,&size,position);
    	   break;
        case 4:
          	printf("enter an element = ");
    	    scanf("%d",&element); 
        	search(arr,&size,element);
        	break;
        case 5:
        	printf("enter an element = ");
        	scanf("%d",&element);
        	printf("enter a new number = ");
        	scanf("%d",&number);
        	replace(arr,&size,element,number);
        	break;
    	default:
    		printf("invalid\n");
    		break;
    }	
	printf(" \n new array is= \n");
	for(i=0;i<size;i++){
		printf("%d",arr[i]);
	}	
	   return 0;
}
