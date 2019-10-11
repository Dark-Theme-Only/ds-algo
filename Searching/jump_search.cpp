// C++ program to implement Jump Search 

#include <bits/stdc++.h> 
using namespace std; 

int jumpSearch(int arr[], int x, int n) 
{ 
	
	int step = sqrt(n); 

	int prev = 0; 
	while (arr[min(step, n)-1] < x) 
	{ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n) 
			return -1; 
	} 


	while (arr[prev] < x) 
	{ 
		prev++; 

		if (prev == min(step, n)) 
			return -1; 
	} 

if (arr[prev] == x) 
		return prev; 

	return -1; 
} 

int main() 
{ 
	int arr[] = { 70, 21, 9, 3, 23, 5, 38, 13, 21 }; 
	int x = 5; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	int index = jumpSearch(arr, x, n); 

	cout << "Number " << x << " is at the index " << index<<endl; 
	return 0; 
} 

