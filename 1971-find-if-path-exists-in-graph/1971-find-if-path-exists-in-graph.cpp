class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination) {
            return true;
        }
        
        vector<bool> visited(n, false);
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++) {
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        queue<int> q;
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()) {
            int s = q.front();
            q.pop();
            
            for(auto& opt: adj[s]) {
                if(opt == destination) {
                    return true;
                }
                if(!visited[opt]) {
                    visited[opt] = true;
                    q.push(opt);
                }                
            }
            
        }
        
        return false;
          
    }
};