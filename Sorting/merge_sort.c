#include<stdio.h>
#include<conio.h>
#include<time.h>
#define max 20

void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void main()
{
	int n,i,a[max],ch=1;
	clock_t start,end;
	clrscr();
	while(ch)
	{
		printf("enter the number of elements\n");
		scanf("%d",&n);
		printf("enter the elements\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		start=clock();
		mergesort(a,0,n-1);
		end=clock();
		printf("the sorted array is:\n");
		for(i=0;i<n;i++)
			printf("%d\n",a[i]);
		printf("\nTime Taken = %lf",(end-start)/CLK_TCK);
		printf("\nDo you wish to continue(0/1)?\n");
		scanf("%d",&ch);
	}
	getch();
}
void mergesort(int a[],int low,int high)
{       int mid;
	delay(100);
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high)
{
	int i,j,k,t[max];
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid) && (j<=high))
	{
		if(a[i]<=a[j])
			t[k++]=a[i++];
		else
			t[k++]=a[j++];
	}
	while(i<=mid)
	{
		t[k++]=a[i++];
	}
	while(j<=high)
	{
		t[k++]=a[j++];
	}
	for(i=low;i<=high;i++)
	{
		a[i]=t[i];
	}
}
