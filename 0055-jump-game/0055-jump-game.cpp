class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,j=nums[0];
        int n=nums.size();
        if (n==1)
            return true;
        for(i=0;i<n-1;i++){
            if(nums[i]==0 && j<=i){
                return false;
            }
            j=max(j,nums[i]+i);
        }
        if(j>=n-1)
            return true;
        return false;
    }
};