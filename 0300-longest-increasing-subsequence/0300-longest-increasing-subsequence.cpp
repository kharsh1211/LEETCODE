class Solution {
public:
    int dp[3001][3001];
    int solve(vector<int>& nums,int i,int prev){
        if(i==nums.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1]; 

        int pick=0;
        if(prev==-1 || nums[i]>nums[prev]){
            pick=1+solve(nums,i+1,i);
        }
        int notpick=solve(nums,i+1,prev);

        return dp[i][prev+1]=max(pick,notpick);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);    
    }
};