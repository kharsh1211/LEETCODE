class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices,int i,bool x){
        if(i>=prices.size()) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        int ans=0;
        if(x==false){
            ans=max(solve(prices,i+1,true)-prices[i],solve(prices,i+1,false));
        } 
        else{
            ans=max(solve(prices,i+2,false)+prices[i],solve(prices,i+1,true));
        }
        return dp[i][x]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);    
    }
};