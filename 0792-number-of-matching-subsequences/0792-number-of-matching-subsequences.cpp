class Solution {
public:
    bool isSubsequence(string& s1, string& s2, int m, int n) {
        int j = 0;
        for (int i = 0; i < m && j < n; i++) {
            if (s1[i] == s2[j])
                j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(words[i]) != mp.end()) {
                ans += mp[words[i]];
            } else {
                mp[words[i]] =
                    isSubsequence(s, words[i], s.length(), words[i].length());
                ans += mp[words[i]];
            }
        }
        return ans;
    }
};