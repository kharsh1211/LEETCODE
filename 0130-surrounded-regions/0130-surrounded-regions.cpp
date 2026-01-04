class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X' || vis[i][j]==1) return;

        vis[i][j]=1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));

        for(int i=0;i<m;i++){
            dfs(0,i,board,vis);
            dfs(n-1,i,board,vis);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,board,vis);
            dfs(i,m-1,board,vis);
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1) board[i][j]='X';
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
        }    

    }
};