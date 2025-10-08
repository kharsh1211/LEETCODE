class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<int>&vis,int i){
        vis[i]=1;
        for(auto x:graph[i]){
            if(!vis[x]) dfs(graph,vis,x);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) graph[i].push_back(j);
            }
        } 
        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(graph,vis,i);
                count++;
            }
        }
        return count;
    }
};