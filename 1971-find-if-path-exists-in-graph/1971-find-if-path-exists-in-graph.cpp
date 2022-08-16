class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==destination)return 1;
            for(auto &a:m[front]){
                if(!visited[a]){
                    q.push(a);
                    visited[a]=1;
                }
            }
        }
        return 0;
    }
};