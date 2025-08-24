class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, int idx, int n, vector<int> temp) {
        ans.push_back(temp);
        for (int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            solve(ans, nums, i + 1, n, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, 0, n, temp);
        return ans;
    }
};
