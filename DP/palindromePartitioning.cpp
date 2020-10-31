// 132. Palindrome Partitioning II

// Problem: Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.

// Code:
    void isPalindrome(int start,int end ,vector<vector<bool>> &ispal, string s){
        if(start < 0 or end >= s.size()) return;
        if(s[start] == s[end]) ispal[start][end] = 1, isPalindrome(start - 1,end + 1, ispal,s);
    }
    
     int memo(int i, vector<vector<bool>> &ispal, vector<int> &dp, string s){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = i;j < s.size();j++){
            if(ispal[i][j]) ans = min(ans,1 + memo(j+1 ,ispal, dp,s));
        }
        return dp[i] = ans;
    }
        
    int minCut(string s) {
        int n = s.size(); 
        vector<int>dp(n,-1);
        vector<vector<bool>>ispal(n,vector<bool>(n,false));
        // using the expansion around the center concept here , to fill up the table of is palindrome
        for(int i = 0;i < s.size();i++){
            isPalindrome(i,i,ispal,s);
            isPalindrome(i,i + 1,ispal,s);
        }
        return memo(0,ispal, dp,s) - 1;
    }
