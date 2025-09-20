class Solution {
public:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==0){
            return 0;
        }
        int gold = grid[i][j];
        grid[i][j] = 0;
        int count=0;

        for(int k=0;k<4;k++){
            int nr=dr[k]+i;
            int nc=dc[k]+j;

            count=max(count,solve(grid,nr,nc));
        }
        grid[i][j] = gold;
        return count+gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;    
    }
};