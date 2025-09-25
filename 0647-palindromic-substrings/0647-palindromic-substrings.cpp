class Solution {
public:
    bool solve(string s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        return dp[i][j] = 0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxl = INT_MIN;
        int sp = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j, dp)) {
                    count++;
                }
            }
        }
        return count;
    }
};
