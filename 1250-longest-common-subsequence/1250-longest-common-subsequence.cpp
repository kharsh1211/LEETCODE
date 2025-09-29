class Solution {
public:
    int t[1001][1001];

    int solve(const string& text1, const string& text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (t[i][j] != -1) return t[i][j];

        if (text1[i] == text2[j])
            return t[i][j] = 1 + solve(text1, text2, i + 1, j + 1);

        int skip1 = solve(text1, text2, i, j + 1);
        int skip2 = solve(text1, text2, i + 1, j);

        return t[i][j] = max(skip1, skip2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};
