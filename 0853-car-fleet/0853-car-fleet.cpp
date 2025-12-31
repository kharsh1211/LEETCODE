class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>ps;
        for(int i=0;i<n;i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end(),comp);
        stack<pair<int,int>>st;
        st.push(ps[0]);
        for(int i=0;i<n;i++){
            double time1=(target-st.top().first)/(double)st.top().second;
            double time2=(target-ps[i].first)/(double)ps[i].second;

            if(time1<time2){
                st.push(ps[i]);
            }
        }
        return st.size();
    }
};