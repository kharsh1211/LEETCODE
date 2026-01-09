class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=cost.size();
        unordered_map<int,long long>mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']+=cost[i];
            sum+=cost[i];
        }
        long long maxc=-1e18;
        for(auto &x:mp){
            maxc=max(maxc,x.second);
        }
        return sum-maxc;
    }
};