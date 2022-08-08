class Solution {
public:
    int helper(int l1,int l2,string &s1,string &s2,vector<vector<int>> &dp){
        if(l1<0 || l2<0) return  0;
        
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        
        if(s1[l1]==s2[l2])
            return dp[l1][l2]= 1+helper(l1-1,l2-1,s1,s2,dp);
        
        return dp[l1][l2]= max(helper(l1-1,l2,s1,s2,dp),helper(l1,l2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int l1=text1.size();
        int l2=text2.size();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return helper(l1-1,l2-1,text1,text2,dp);
    }
};