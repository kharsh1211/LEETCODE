class Solution {
public:
    int dp[45][20001];
    int solve(vector<int>& nums, int target, int XOR, int i, int n){
        if(XOR==target) return 0;
        if(i>=n) return 1e9;

        if(dp[i][XOR]!=-1) return dp[i][XOR];

        int pick=1+solve(nums,target,XOR^nums[i],i+1,n);
        int notpick=solve(nums,target,XOR,i+1,n);

        return dp[i][XOR]=min(pick,notpick);
    }
    int minRemovals(vector<int>& nums, int target) {
        int XOR=0;
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }   
        int ans=solve(nums,target,XOR,0,n);
        return ans>=1e9?-1:ans; 
    }
};