class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> q;
        vector<bool> visited(s.length() + 1, false);
        
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            
            if (start == s.length()) return true;
            
            for (const string& word : wordDict) {
                int len = word.length();
                if (start + len <= s.length()) {
                    if (s.substr(start, len) == word) {
                        if (!visited[start + len]) {
                            visited[start + len] = true;
                            q.push(start + len);
                        }
                    }
                }
            }
        }
        
        return false;
    }
};