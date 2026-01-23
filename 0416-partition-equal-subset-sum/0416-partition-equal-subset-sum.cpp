class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>& nums,int i,int sum){
        if(sum<0 || i == nums.size()) return false;
        if(sum==0) return true;

        if(dp[i][sum]!=-1) return dp[i][sum];

        bool pick=solve(nums,i+1,sum-nums[i]);
        bool notpick=solve(nums,i+1,sum);

        return dp[i][sum]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }    
        if(sum%2==1) return false;
        else return solve(nums,0,sum/2);
    }
};