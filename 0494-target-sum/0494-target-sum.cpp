class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int sum,vector<vector<int>>&dp,int offset){
        if(i==nums.size()) return (sum==target)?1:0;
        if(dp[i][sum + offset] != -1) return dp[i][sum + offset];
        int add=solve(nums,target,i+1,sum+nums[i],dp,offset);
        int sub=solve(nums,target,i+1,sum-nums[i],dp,offset);

        return dp[i][sum + offset]=add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int total=0;
        for(int x : nums) {
            total += x;
        }
        int offset = total;
        vector<vector<int>>dp(n+1,vector<int>(2*total+1,-1));
        return solve(nums,target,0,0,dp,offset);
    }
};