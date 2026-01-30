class Solution {
public:
    int dp[5001][101];
    int offset=2000;
    int solve(vector<int>& nums, int target, int i){
        if(i>=nums.size()){
            if(target==0) return 1;
            else return 0;
        }
        if(dp[target+offset][i]!=-1) return dp[target+offset][i];
        int add=solve(nums,target-nums[i],i+1);
        int subs=solve(nums,target+nums[i],i+1);

        return dp[target+offset][i]=add+subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);    
    }
};