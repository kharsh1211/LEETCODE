class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        if(lower!=nums.end() && *lower==target){
            ans[0]=lower - nums.begin();
            ans[1]=upper - nums.begin()-1;
        }
        return ans;
    }
};