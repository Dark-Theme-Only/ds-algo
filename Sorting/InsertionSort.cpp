#include<iostream>

using namespace std;

//a function to implement Insertion Sort

int InsertionSort(int arr[],int n)
{	
	//initially bound before arr[1]

	int bound=1,j,curr;
	for(int i = 1; i < n; i++)
	{	
		//marking the current element 
		//which has to be shifted	
		curr=a[i];
		j=i-1;
		
		//shifting all other elements in
		//to one place right
		while(j >=0 && arr[j] > curr)
		{
			arr[j + 1] = arr[j];  
                        j-- ; 
		}
		arr[j + 1]= curr;
		bound++;
	}

}

//Driver's Code
int main()
{
	int arr[] = {142, 68, 31, 29, 10, 5, 2};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    InsertionSort(arr, n);  
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}
