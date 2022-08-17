class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        vector<int> visited(n, false);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto i:restricted)
            visited[i]=1;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int ans = 1;
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            for(auto v: adj[u]) {
                if(visited[v] == false) {
                    visited[v] = true;
                    q.push(v);
                    ans++;
                }
            }
        }
        return ans;
    }
};