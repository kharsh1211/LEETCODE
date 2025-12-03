class Solution {
public:
    int n;
    unordered_set<string>wl;
    int dp[301];
    bool solve(int idx,string &s){
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        if(wl.find(s)!=wl.end()) return true;

        for(int l=0;l<n;l++){
            if((wl.find(s.substr(idx,l))!=wl.end()) && solve(idx+l,s)) return true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for (auto &word : wordDict) {
            wl.insert(word);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s);  
    }
};