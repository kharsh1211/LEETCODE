class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool hasCycle(int node, int parent) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, node)) return true;
            }
            else if (neighbor != parent) {
                return true;
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

            adj[u].push_back(v);
            adj[v].push_back(u);

            visited.assign(n + 1, false);

            if (hasCycle(u, -1)) {
                return edge;
            }
        }

        return {};
    }
};