class Solution{

public:


    int lis(int idx, vector<int> &nums,vector<int>& dp){ 
        if(dp[idx] != -1) 
            return dp[idx]; 
        int ans = 1;
        for(int j = 0; j < idx; ++j) { 
            if(nums[idx]> nums[j]){ 
                ans = max(ans, lis(j, nums,dp) + 1); 
            }
        } 
        return dp[idx] = ans;
    }

    int lengthOfLIS(vector<int>& nums) { 
        vector<int>dp(nums.size()+1,-1);

        int ans = 0; 
        for(int i = 0; i < nums.size(); ++i){
            ans=max(ans, lis(i, nums,dp));
        }
        return ans;
    }
};