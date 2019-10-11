#include<bits/stdc++.h>
using namespace std;
void heapify(int A[], int high, int low)
	{
		int r = 2*low + 2; 
    	int largest = low;  
    	int l = 2*low + 1; 
    	if (l < high && A[l] > A[largest])
    	    largest = l;
   		 if (r < high && A[r] > A[largest])
        	largest = r;
    	if (largest != low)
    	{
    	    swap(A[low],A[largest]);
    	    heapify(A, high, largest);
    	}
	}
	void heapSort(int A[], int low, int high)
	{
    	for (int i = high / 2 - 1; i >= 0; i--)
    	    heapify(A, high, i);
    	for (int i=high-1; i>=0; i--)
    	{
    	    swap(A[0],A[i]);
    	    heapify(A, i, 0);
    	}
	}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    heapSort(arr,0,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}
