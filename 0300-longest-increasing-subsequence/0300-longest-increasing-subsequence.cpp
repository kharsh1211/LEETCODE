class Solution {
public:
    int solve(vector<int>& nums,int idx,int n,int prev,vector<vector<int>>&dp){
        if(idx>=n) return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int take=0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take=1+solve(nums,idx+1,n,idx,dp);
        }
        int skip=solve(nums,idx+1,n,prev,dp);

        return dp[idx][prev+1]=max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,n,prev,dp);    
    }
};