#include <iostream>
using namespace std;

int partition(int *a,int start,int end){
    int i=start-1;
    int j=start;
    int pivot=a[end];
    for( ;j<=end-1;){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
        j=j+1;
    }
    //when comes out from loop place pivot element in the miidle so that element behind it is less and after the pivot is greator than pivot
    swap(a[i+1],a[end]);
    
    //return pivot element 
    return i+1;

    }

void quickSort(int *a,int start,int end)
{
//base case if array have 0 and 1 element
if(start>=end){
    return;
}

//get from function partition
    int p=partition(a,start,end);
//left part
    quickSort(a,start,p-1);
//right part
    quickSort(a,p+1,end);
}




int main() {
int arr[]={1,5,2,6,3,4};
int n=sizeof(arr)/sizeof(int);

quickSort(arr,0,n-1);
//printing result of array after sorting
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
