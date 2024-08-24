#include<stdio.h>

void bubble(int arr[], int *size){
	int i,t,j;
		for(i=0;i<*size;i++)
	{
		for(j=0;j<*size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
			
		}
	 }
}
void selection(int arr[], int *size,int pos){
	int i,j,t;
	 for(i=0;i<*size-1;i++)
	 {
	 	pos=i;
	 	for(j=i+1;j<*size;j++)
	 	{
	 		if(arr[pos]>arr[j])
	 		{
	 			pos=j;
			 }
		 }
		 if(i!=pos)
		 {
		 	t=arr[i];
		 	arr[i]=arr[pos];
		 	arr[pos]=t;
		 }
	 }
}
void insertion(int arr[],int *size,int val){
	int i,j;
	     for ( i = 1; i<*size; i++)
     {
        val=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>val)
        {
            /* code */
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=val;   
     }
}

int main()
{
	int arr[100],i;
	int size=0,option,pos,val;
	
	printf("enter the number of elements= ");
	scanf("%d",&size);
	
	printf("the elements are = \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("the given array is = \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	  printf("\nchoose an option: \n");
    printf("1. bubble sort:\n");
    printf("2. selection sort:\n");
    printf("3. insertion sort:\n");
    scanf("%d",&option);
    switch(option)
	{
    	case 1: 
    	bubble(arr,&size);
        break;
    	case 2: 
    	printf("enter a position=\n");
    	scanf("%d",&pos);
    	selection(arr,&size,pos);
    	break;
		case 3: 
    	printf("enter a value=\n");
    	scanf("%d",&val);
    	insertion(arr,&size,val);
    	break;   
    	default:
		printf("invalid");
		break;
	}
	printf("sorted array is=\n");
		for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
