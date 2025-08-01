class Solution {
public:
    int solve(int n,int i,vector<int>&dp){
        if(i==n) return 1;
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];

        int one=solve(n,i+1,dp);
        int two=solve(n,i+2,dp);

        return dp[i]= one + two;
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(n,0,dp);    
    }
};