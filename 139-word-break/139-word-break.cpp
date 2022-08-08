class Solution {
public:
    
    bool isValid(int l , string &s , unordered_map <string , bool> &umap , vector <int> &dp ){
        int n = s.size();
        if(l == n)return true;
        if(dp[l] != -1)return dp[l];
        string temp = "";
        bool ans = false;
        for(int k = l ; k < n ; ++k){
            temp += s[k];
            if(umap[temp] == true){
               ans |= isValid(k + 1 , s , umap , dp);
            }
        }
        return dp[l] = ans;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map <string , bool> umap;
        for(auto it : wordDict){
            umap[it] = true;
        }
        int n = s.size();
        vector <int> dp(n + 1 , -1);
        return isValid(0 , s , umap , dp);
    }
};