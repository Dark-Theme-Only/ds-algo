#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int arr[],int n);
void insertion_sort(int arr[],int n)
{
    int j,i,key;
    for(j=1;j<n;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    printf("\nSorted Array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    clock_t t1,t2;
    double t3;
    int n,i;
    printf("Enter the no. of elements in the array.\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element.\n",i+1);
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
    return 0;
}

