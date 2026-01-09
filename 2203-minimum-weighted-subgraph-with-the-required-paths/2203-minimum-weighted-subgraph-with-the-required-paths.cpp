class Solution {
public:
    vector<long long> djikstra(vector<vector<pair<int,int>>>&graph,int s,int n){
        vector<long long>dist(n,1e18);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;

        dist[s]=0;
        pq.push({0,s});

        while(!pq.empty()){
            int node=pq.top().second;
            long long w=pq.top().first;
            pq.pop();

            if(w>dist[node]) continue;

            for(auto &x:graph[node]){
                int f=x.first;
                int wt=x.second;
                long long nwt=w+wt;
                if(nwt<dist[f]){
                    dist[f]=nwt;
                    pq.push({nwt,f});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        int m=edges.size();
        vector<vector<pair<int,int>>>graph(n),rev_graph(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            graph[u].push_back({v,w});
            rev_graph[v].push_back({u,w});
        } 
        vector<long long> sp1=  djikstra(graph,src1,n);
        vector<long long> sp2= djikstra(graph,src2,n);
        vector<long long> sp3= djikstra(rev_graph,dest,n);
        long long ans=1e18;
        for(int i=0;i<n;i++){
            if(sp1[i]==1e18 || sp2[i]==1e18 || sp3[i]==1e18) continue;
            ans=min(ans,sp1[i]+sp2[i]+sp3[i]);
        }
        return ans==1e18?-1:ans;
    }
};