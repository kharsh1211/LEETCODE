class Solution {
public:
    int solve(vector<int>&nums,int i,int j){
        if(i>j)
            return 0;
        
        int left = nums[i]+min(solve(nums,i+1,j-1),solve(nums,i+2,j));
        int right = nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        
        return max(left,right);
    }        
        
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(nums,0,n-1);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(ans>=sum-ans)
            return true;
        else
            return false;
    }
};