class Solution {
public:
    int dp[1001];
    bool solve(string s, unordered_set<string>&st,int i){
        if(i==s.size()) return true;

        if(dp[i]!=-1) return dp[i];

        for(int x=i;x<s.size();x++){
            if(st.count(s.substr(i,x-i+1)) && solve(s,st,x+1)) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        int n=wordDict.size();
        return solve(s,st,0);
    }
};