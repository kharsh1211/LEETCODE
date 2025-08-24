class Solution {
public:
    char solve(int n, int k) {
        if (n == 1) return '0';
        int length = (1 << n) - 1;
        int mid = (length + 1) / 2;
        if (k == mid) {
            return '1';
        } 
        else if (k < mid) {
            return solve(n - 1, k);
        } 
        else {
            int mirror_pos = length - k + 1;
            char c = solve(n - 1, mirror_pos);
            return c == '1' ? '0' : '1';
        }
    }
    
    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};
