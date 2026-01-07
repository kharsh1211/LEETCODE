class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n+1,vector<int>(m+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int w=pq.top().first;
            pq.pop();

            if(r==n-1 && c==m-1) return w;

            // if(dist[r][c]<w) continue;

            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nw=max(w,abs(heights[nr][nc]-heights[r][c]));
                    if(nw<dist[nr][nc]){
                        pq.push({nw,{nr,nc}});
                        dist[nr][nc]=nw;
                    }
                }
            }

        }
        return 0;
    }
};