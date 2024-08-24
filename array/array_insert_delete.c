#include<stdio.h>
int arr[100];
int size=0;

void insert_first(int element){
	int i;
	for(i=size-1;i>=0;i--){
		arr[i+1]=arr[i];
	}
	arr[0]=element;
	size++;
}
void insert_last(int element){
	arr[size]=element;
	size++;
}
void insert_position(int element,int pos){
	int i;
	for(i=size-1;i>=pos;i--){
		arr[i+1]=arr[i];
	}
	arr[pos]=element;
	size++;
}
int delete_first(){
	int i;
	return arr[0];
	for(i=0;i<size;i++){
		arr[i]=arr[i+1];
	}
	size--;
}
int delete_last(){
	return arr[size-1];
	size--;
}
int delete_pos(int pos){
	int i;
	return arr[pos];
	for(i=pos;i< size;i++){
		arr[i]=arr[i+1];
	}
	size--;
	
}
int main(){
	int element,i,pos;
	
	printf("enter number of element:");
	scanf("%d",&size);
	printf("enter the elements:\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("the elements:\n");
	for(i=0;i<size;i++){
		printf("%d",arr[i]);
	}
	printf("enter the the element to enter:");
	scanf("%d",&element);
//	insert_first(element);
//insert_last(element);
printf("enter the position:");
scanf("%d",&pos);
//insert_position(element,pos);
printf("delete element is %d\n",delete_first(element));
	for(i=0;i<size;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
