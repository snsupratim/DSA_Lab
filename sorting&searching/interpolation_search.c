#include<stdio.h>
#include<conio.h>
int a[100],n;

int interpolation(int low,int high,int key){
	int middle;
	if(low<=high && key<=a[high] && key>=a[low]){
		middle=(low+(high-low) )*((key-a[low])/(a[high]-a[low])) ;
		
		if(a[middle]==key){
			return middle;
		}
		else if(a[middle]<key){
			return interpolation(middle+1,high,key);
		}
		else if(a[middle]>key){
			return interpolation(0,middle-1,key);
		}
	}
	else{
		return -1;
	}
}

int main(){
	int i,elements;
	int key;
	int index;
	printf("enter the number elements=");
	scanf("%d",&n);
	printf("enter the elements=\n");
	for(i=0;i<n;i++){
		scanf("%d ",&a[i]);
	}
	printf("elements are: \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	printf("enter the value to be searched :");
	scanf("%d",&key);
	
	index=interpolation(0,n-1,key);
	if(index!=-1){
		printf("%d is found at %d position:",key,index);
	}
	else{
		printf("%d is not prsent:",key);
	}
}
