// 517. Super Washing Machines

// Code:

class Solution {
public:
    int findMinMoves(vector<int>& nums) {
        int s=0;
        for(auto m:nums){
            s+=m;
        }
        int n=nums.size();
        if(s%n!=0) return -1;
        else{
            int re=s/n,ans=0,co=0;
            for(int i=0;i<nums.size();i++){
                co+=nums[i]-re;
                ans=max(ans,max(abs(co),nums[i]-re));
            }
            return ans;
        }
    }
};
