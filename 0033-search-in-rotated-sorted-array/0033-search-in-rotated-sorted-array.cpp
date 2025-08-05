class Solution {
public:
    bool check(vector<int>& nums, int index, int target) {
        int n = nums.size();
        int pivot_val = nums.back();

        bool is_num_in_right = (nums[index] <= pivot_val);
        bool is_target_in_right = (target <= pivot_val);

        if (is_num_in_right && !is_target_in_right) {
            return true;
        }
        if (!is_num_in_right && is_target_in_right) {
            return false;
        }
        return nums[index] >= target;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, target) == true) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1 && nums[ans] == target) {
            return ans;
        } else {
            return -1;
        }
    }
};