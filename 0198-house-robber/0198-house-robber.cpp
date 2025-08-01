class Solution {
public:
    int solve(vector<int>& nums,int i,int sum,vector<vector<int>>&dp){
        if(i>nums.size()-1) return 0;

        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=nums[i]+solve(nums,i+2,sum+nums[i],dp);
        int notpick=solve(nums,i+1,sum,dp);

        return dp[i][sum]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(100000,-1));
        return solve(nums,0,0,dp);    
    }
};