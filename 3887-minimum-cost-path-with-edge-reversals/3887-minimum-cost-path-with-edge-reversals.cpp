class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>>&grid,int n,int i,vector<int>&vis,vector<int>&dist){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,i});
        dist[i]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int w=pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;

            for(auto &x:grid[node]){
                if(!vis[x.first] && dist[x.first]>w+x.second){
                    dist[x.first]=w+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        return dist;
    }
    int minCost(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<pair<int,int>>>grid(n);

        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];

            grid[u].push_back({v,w});
            grid[v].push_back({u,2*w});
        } 
        vector<int>vis(n,0);
        vector<int>dist(n,1e9);
        vector<int> ans=dijkstra(grid,n,0,vis,dist);   

        return ans[n-1]==1e9?-1:ans[n-1];
    }
};