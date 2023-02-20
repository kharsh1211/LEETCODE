class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while(l<=h){
            m = (l + h) / 2;
            if(target == nums[m]){
                return m;
            }
            if(target > nums[m]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        if(target>nums[m]){
            return m+1;
        }
        else{
            return m;
        }
    }
};