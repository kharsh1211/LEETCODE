class Solution {
public:
    int dfs(int i, int j,vector<vector<int>>& grid,  vector<vector<bool>> &vis){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || vis[i][j] || grid[i][j]==0) 
            return 0;
        vis[i][j]=1;
        return 1 + dfs(i-1, j, grid, vis) + dfs(i, j-1, grid, vis) + dfs(i+1, j, grid, vis) + dfs(i, j+1, grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans, dfs(i, j, grid, vis));
                }
            }
        }
        return ans;
    }
};