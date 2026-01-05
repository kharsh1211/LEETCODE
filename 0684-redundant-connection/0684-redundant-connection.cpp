class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int src, int target) {
        if (src == target) return true;
        visited[src] = true;
        
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, target)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            visited.assign(n + 1, false);
            
            if (dfs(u, v)) {
                return edge;
            }
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};