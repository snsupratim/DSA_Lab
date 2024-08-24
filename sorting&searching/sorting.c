#include<stdio.h>
int a[10],n;
//Selection sort
void selection()
{
int i,j,t,min,pos;
for(i=0;i<n-1;i++)
{
min=a[i];
pos=i;
for(j=i+1;j<n;j++)
{
if(a[j]<min)
{
min=a[j];
pos=j;
}
}
if(i!=pos)
{
t=a[i];
a[i]=a[pos];
a[pos]=t;
}
}
}
//Bubble sort
void bubble()
{
int i,j,t;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]<a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
}

//Insertion sort
void insertion()
{
int i,j,k,t;
for(k=1;k<n;k++)
{
t=a[k];
j=k-1;

while(j>=0 && a[j]>t)
{
a[j+1]=a[j];
j--;
}
a[j+1]=t;
}
}
//Quick sort
int partition(int l,int u)
{
int i=l,j=u,t;
while(i<j)
{
while(a[i]<a[l])
i++;
while(a[j]>a[l])
j--;
if(i<j)
{
t=a[i];
a[i]=a[j];
a[j]=t;
}

}
t=a[l];
a[i]=a[j];
a[j]=t;
return j;
}
void qsort(int l,int u)
{
int p;
if(l<u)
{
p=partition(l,u);
qsort(l,p-1);
qsort(p+1,u);
}
}

//Merge sort
void merge(int l,int mid,int u)

{
int t[10],i,j,k;
i=l;
j=mid+1;
k=l;
while(i<=mid&&j<=u)
{
if(a[i]<=a[j])
{
t[k++]=a[i++];
}
else

{
t[k++]=a[j++];
}

}
while(i<=mid)
t[k++]=a[i++];
while(j<=u)
t[k++]=a[j++];
for(i=l;i<=u;i++)
a[i]=t[i];

}
void msort(int l,int u)
{
int mid;
if(l<u)
{
mid=(l+u)/2;
msort(l,mid);
msort(mid+1,u);
merge(l,mid,u);
}
}
int main()
{
int ch,i;
while(1)
{

printf("\n 1.selectiom 2. bubble 3.insertion 4.quick 5.Merge 6.Exit");

printf("\n Enter choice of sorting:");
scanf("%d",&ch);
if(ch==6)
return 0;
printf("\nArray Size:");

scanf("%d",&n);

printf("Enter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
switch(ch)
{
case 1:
selection();
break;

case 2:
bubble();
break;
case 3:
insertion();
break;
case 4:
qsort(0,n-1);
break;

case 5:
msort(0,n-1);
break;

}

printf("\nAfter sorting elements:");

for(i=0;i<n;i++)
printf("%d", a[i]);
}

}
