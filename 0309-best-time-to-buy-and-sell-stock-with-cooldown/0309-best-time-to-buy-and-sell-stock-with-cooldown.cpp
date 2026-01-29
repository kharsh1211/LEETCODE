class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices,int i,bool x){
        if(i>=prices.size()) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        if(x==false){
            int buy=solve(prices,i+1,true)-prices[i];
            int skip=solve(prices,i+1,false);
            return dp[i][x]=max({buy,skip});
        } 
        else{
            int sell=solve(prices,i+2,false)+prices[i];
            int skip=solve(prices,i+1,true);
            return dp[i][x]=max({sell,skip});
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);    
    }
};