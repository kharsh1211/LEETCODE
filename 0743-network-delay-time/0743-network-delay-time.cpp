class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int ,int>>>graph(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];

            graph[u].push_back({v,w});

        }  
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(wt>dist[node]) continue;

            for(auto &x:graph[node]){
                int newDist = wt + x.second;
                if(dist[x.first]>newDist){
                    dist[x.first]=newDist;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());

        return ans==1e9?-1:ans;
    }
};