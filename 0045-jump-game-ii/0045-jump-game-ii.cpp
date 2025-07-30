class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int jumps=10000001;
        for(int k=1;k<=nums[i];k++){
            if (i + k < nums.size()) {
                jumps=min(jumps,1+solve(nums,i+k,dp));
            }
        }
        return dp[i]= jumps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);    
    }
};