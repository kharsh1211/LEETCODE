class Solution {
public:
    void dfs(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>&vis){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || vis[i][j]==1 || heights[i][j]<prev) return;
        vis[i][j]=1;

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int k=0;k<4;k++){
            dfs(heights,i+dx[k],j+dy[k],heights[i][j],vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>ans;

        vector<vector<int>>pacVis(n,vector<int>(m,0));
        vector<vector<int>>atlVis(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            dfs(heights,0,i,-1,pacVis);
            dfs(heights,n-1,i,-1,atlVis);
            
        }
        for(int i=0;i<n;i++){
            dfs(heights,i,0,-1,pacVis);
            dfs(heights,i,m-1,-1,atlVis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacVis[i][j]==1 && atlVis[i][j]==1) ans.push_back({i,j});
                cout<<pacVis[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans;
             
    }
};