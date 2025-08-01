class Solution {
public:
    int solve(vector<int>& nums,int i,int e,vector<int>&dp){
        if(i>e) return 0;

        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+solve(nums,i+2,e,dp);
        int notpick=solve(nums,i+1,e,dp);

        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
    }
};