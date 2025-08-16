class Solution {
public:
    long long solve(vector<int>& nums,int x){
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;

        while (j < n) {
            if (nums[j] <= x) {
                ans+=(j-i+1);
            }
            else{
                i=j+1;
            }
            j++;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return (int)(solve(nums,right)-solve(nums,left-1));
        
    }
};