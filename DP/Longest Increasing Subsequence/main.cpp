#include <iostream>

using namespace std;

#define MAX 1000

int LIS(int* arr,int N)
{
    // In this dp array dp[i] represents the length of the longest Increasing subsequence  
    // ending on arr[i]
    int dp[MAX];
    dp[0]=1;
    // Initializing with 1 since every element will be a part of subsequence consisting itself
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
    }
    // for every i it will check if there is any subsequence form 0 to i-1 which it can extend
    // it can only extend a LIS if it is greater than its last element 
    for(int i=1;i<N;i++)
    {
        int max_lis=0; // has the length of maximum LIS which arr[i] can extend
        int temp=0;
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]<arr[i]){
                temp=dp[j];
            }
            if(temp>max_lis){
                max_lis=temp;
            }
        }
        dp[i]=max_lis+dp[i];
    }
    int ans=0;
    // find the maximum lis chain
    for(int i=0;i<N;i++)
    {
        if(dp[i]>ans){ans=dp[i];}
    }
    return ans;
}

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cout<<LIS(arr,N)<<endl;
    return 0;
}
