class Solution {
public:
    int n, m;
    // int dp[201][201][1001];
    vector<vector<vector<int>>>dp;

    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        if (k < 0 || i >= n || j >= m) return -1e9;
        if (i == n - 1 && j == m - 1) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];


        int ans = -1e9;
        if(i+1<n) ans = max(ans,grid[i+1][j]+solve(grid, i+1, j, k-(grid[i+1][j]>0)));
        if(j+1<m) ans = max(ans,grid[i][j+1]+solve(grid, i, j+1, k-(grid[i][j+1]>0)));

        return dp[i][j][k] = ans;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        // memset(dp,-1,sizeof(dp));
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        int res=solve(grid, 0, 0, k);
        return res<0?-1:res;
    }
};
