class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for(int k=0;k<4;k++){
                        int nr=i+dx[k];
                        int nc=j+dy[k];
                        if(nr<0 || nr>=n || nc<0 || nc>=m) count++;
                        else if(grid[nr][nc]==0) count++;
                    }
                }
            }
        }
        return count;
    }
};