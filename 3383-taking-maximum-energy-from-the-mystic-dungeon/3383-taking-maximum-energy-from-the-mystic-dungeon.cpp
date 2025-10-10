class Solution {
public:
    int solve(vector<int>& energy, int k,int idx,vector<int>&dp){
        if(idx>=energy.size()) return -1e9;
        if(dp[idx]!=-1) return dp[idx];
        int take=energy[idx];
        if(k+idx<energy.size()){
            take+=solve(energy,k,idx+k,dp);
        }
        return dp[idx]=take;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=-1e9;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,solve(energy,k,i,dp));    
        }
        return ans; 
    }
};