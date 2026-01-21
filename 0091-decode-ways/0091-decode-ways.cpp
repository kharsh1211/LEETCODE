class Solution {
public:
    int dp[101];
    int solve(string s,int i){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int a=solve(s,i+1);
        int b=0;
        if(s[i]!=0 && i+1<s.size() && stoi(s.substr(i,2))<=26){
            b=solve(s,i+2);
        }
        return dp[i]=a+b;

    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);

    }
};