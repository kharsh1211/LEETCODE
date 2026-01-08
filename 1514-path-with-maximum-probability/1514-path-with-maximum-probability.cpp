class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>graph(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];

            graph[u].push_back({v,w});
            graph[v].push_back({u, w});

        }    
        vector<double>dist(n,0.0);
        dist[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            int node=pq.top().second;
            double wt=pq.top().first;
            pq.pop();
            if (wt < dist[node]) continue;

            for(auto&x:graph[node]){
                double nwt=wt*x.second;
                if(nwt>dist[x.first]){
                    dist[x.first]=nwt;
                    pq.push({nwt,x.first});
                }
            }
        }
        return dist[end_node];
    }
};