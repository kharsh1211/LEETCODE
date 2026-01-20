// class Solution {
// public:
//     bool solve(string s, int i, int j, vector<vector<int>>& dp) {
//         if (i >= j)
//             return 1;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == s[j])
//             return dp[i][j] = solve(s, i + 1, j - 1, dp);
//         return dp[i][j] = 0;
//     }
//     string longestPalindrome(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         int maxl = INT_MIN;
//         int sp = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 if (solve(s, i, j, dp)) {
//                     if(maxl<j-i+1){
//                         maxl=j-i+1;
//                         sp=i;
//                     }
                   
//                 }
//             }
//         }
//         return s.substr(sp,maxl);    
//     }
// };
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};