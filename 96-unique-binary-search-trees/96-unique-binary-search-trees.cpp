class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&dp){
        //base case
        if(i>j)
            return 1;
        //check the cache
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=0;
        for(int k=i;k<=j;k++){
            int left=  solve(i,k-1,dp);
            int right= solve(k+1,j,dp);
             res+= (left * right);
        }
        return dp[i][j]=res;
    }
    int numTrees(int n) {
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};