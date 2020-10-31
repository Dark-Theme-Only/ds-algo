// 887. Super Egg Drop

//Time complexity is O((e * f) * loge )
// Space complexity is O(e*f)
// where e = number of eggs & f = number of floors

 int solve(int e,int f,vector<vector<int>>& dp)
      {
        int ans = INT_MAX;
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        if(dp[e][f] != -1)
            return dp[e][f];
        int l = 1,h = f,temp = 0;
                while(l<=h)
                {
                        int mid = l + (h-l)/2;
                        int left = solve(e-1,mid-1,dp);
                        int right = solve(e,f-mid,dp);
                        temp = 1 + max(left,right);
                        if(left<right)
                        {
                                l = mid +1;
                        }
                        else
                        {
                                h = mid - 1;
                        }
                        ans = min(ans,temp);
                }
        return dp[e][f] = ans;
      }
      int superEggDrop(int e, int f) 
      {
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
              
   }
