class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(amount<0 || i==coins.size()){
            return 100000;
        }
        if(amount==0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int pick=1+solve(coins,amount-coins[i],i,dp);
        int notpick=solve(coins,amount,i+1,dp);

        return dp[i][amount]=min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,0,dp);
        return (ans<100000)?ans:-1;
    }
};