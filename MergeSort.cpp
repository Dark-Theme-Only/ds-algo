#include<bits/stdc++.h> 
 
void merge(int arr[], int l, int m, int r) // Function to merge subarrays
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1)    //Copying Remaining Elements of L
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 


	while (j < n2)      //Copying Remaining Elements of R
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 

		int m = l+(r-l)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 


int main() 
{ 
	int arr[] = {2, 9, 3, 15, 1, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	mergeSort(arr, 0, n - 1); 
  
  for(int i=0;i<n;i++)
  cout<<arr[i]<<endl;
	return 0; 
} 
