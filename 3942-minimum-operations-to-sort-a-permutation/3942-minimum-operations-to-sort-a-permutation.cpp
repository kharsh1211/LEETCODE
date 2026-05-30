class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int kA = nums[0];
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + kA) % n) {
                asc = false;
                break;
            }
        }

        if (asc) {
            if (kA == 0) return 0;
            return min(n - kA, kA + 2);
        }
        int kB = (n - 1 - nums[0] + n) % n;
        bool desc = true;
        for (int i = 0; i < n; i++) {
            int expected = (n - 1 - ((i + kB) % n) + n) % n;
            if (nums[i] != expected) {
                desc = false;
                break;
            }
        }
        if (desc) {
            return min(kB + 1, n - kB + 1);
        }
        return -1;
    }
};