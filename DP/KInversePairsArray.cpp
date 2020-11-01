// Problem: 629. K Inverse Pairs Array

// Problem Statement: Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.
// We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.
// Since the answer may be very large, the answer should be modulo 109 + 7.

// Code:
class Solution {
public:
    int kInversePairs(int n, int k) {
        // we just need the last row of DP table.
        auto hash = [](int x) {
            return x%2;
        };
        // modular sum helper funciton
        auto mod_sum =[](int x,int y) {
            if(x+y>=0)
                return (x+y)%1000000007;
            else
                return (x+y+1000000007)%1000000007;
        };
        // O(k) space DP table
        vector<vector<int>> dp(2, vector<int>(k+1,0));
        dp[hash(0)][0] = 1;
        // main loop
        for(int i=1;i<=n;i++)
        {
            fill(dp[hash(i)].begin(),dp[hash(i)].end(),0);
            for(int j=0,tmp=0; j<=k;j++)
            {
                int pos = dp[hash(i-1)][j];
                int neg = (j>=i)?-dp[hash(i-1)][j-i]:0;
                int dif = mod_sum(pos,neg);    
                tmp = mod_sum( tmp, dif);
                dp[hash(i)][j] = mod_sum(tmp, dp[hash(i)][j]);
            }
        }
        
        return dp[hash(n)][k];
    }
};
