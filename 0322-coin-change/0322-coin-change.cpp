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
        int count = 100000;
        for (int idx = i; idx < coins.size(); idx++) {
            int res = solve(coins, amount - coins[idx], idx, dp);
            if (res != 100000) {
                count = min(count, 1 + res);
            }
        }
        return dp[i][amount]=count;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,0,dp);
        return (ans<100000)?ans:-1;
    }
};