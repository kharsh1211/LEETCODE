class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (const int num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(num));
            } else {
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};