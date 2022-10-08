class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closesum;
        int mindiff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++){
            int j = i+1,k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target) return target;
                if(abs(target-sum)<mindiff){
                    closesum = sum;
                    mindiff = abs(target-sum);
                }
                if(sum>target) k--;
                else j++;
            }
            
        }
        return closesum;
    }
};