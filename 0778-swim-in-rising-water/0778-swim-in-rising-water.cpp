class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>time(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        time[0][0]=grid[0][0];

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int t=pq.top().first;
            pq.pop();

            if(r==n-1 && c==n-1) return t;
            if(t > time[r][c]) continue; 

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newt = max(t, grid[nr][nc]);

                    if(newt<time[nr][nc]){
                        time[nr][nc]=newt;
                        pq.push({newt,{nr,nc}});
                    }

                }
            }

        }
        return -1;

    }
};