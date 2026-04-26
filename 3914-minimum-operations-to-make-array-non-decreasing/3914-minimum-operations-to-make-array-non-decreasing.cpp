class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]) sum+=1LL*(nums[i]-nums[i+1]);
        }    
        return sum;
    }
};