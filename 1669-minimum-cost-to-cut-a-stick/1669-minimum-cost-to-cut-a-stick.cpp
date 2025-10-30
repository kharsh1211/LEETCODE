class Solution {
public:
    int dp[101][101];
    int solve(int l,int r,vector<int>& cuts,int st,int en){
        if(st>en) return 0;

        if(dp[st][en]!=-1) return dp[st][en];

        int ans=INT_MAX;
        for(int i=st;i<=en;i++){
            ans=min(ans,r-l+solve(l,cuts[i],cuts,st,i-1)+solve(cuts[i],r,cuts,i+1,en));
        }
        return dp[st][en]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return solve(0,n,cuts,0,cuts.size()-1);

    }
};