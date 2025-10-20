class Solution {
public:
    int solve(int n,int i,vector<int>&dp){
        if(i==n) return 1;
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];

        int ways=0;

        for(int j=1;j<=2;j++){
            ways+=solve(n,i+j,dp);
        }

        return dp[i]= ways;
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(n,0,dp);    
    }
};