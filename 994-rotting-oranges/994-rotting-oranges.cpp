class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j}), grid[i][j]=-1;
            }
        }
        queue<pair<int,int>> tmp, empty; int ans=0;
        while(!q.empty()){
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int i = it.first, j = it.second;
                if(i>0 && grid[i-1][j]==1)
                    grid[i-1][j]=-1, tmp.push({i-1,j});
                if(i<m-1 && grid[i+1][j]==1)
                    grid[i+1][j]=-1, tmp.push({i+1,j});
                if(j>0 && grid[i][j-1]==1)
                    grid[i][j-1]=-1, tmp.push({i,j-1});
                if(j<n-1 && grid[i][j+1]==1)
                    grid[i][j+1]=-1, tmp.push({i,j+1});
            }
            if(!tmp.empty())
                ans++;
            q=tmp;
            tmp=empty;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};