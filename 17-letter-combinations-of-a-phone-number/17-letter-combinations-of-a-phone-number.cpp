class Solution {
public:
    vector<string> v = { "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void rec(string &digits,int curr_inx,int last_inx, string s, vector<string> &ans)
    {
        string curr = v[digits[curr_inx] - 49];
        
        for(int i = 0; i < curr.size(); i++)
        {
            if(curr_inx == last_inx)
                ans.push_back(s + curr[i]);
            else
                rec(digits, curr_inx + 1, last_inx, s + curr[i], ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        int len = digits.size();
        if(len == 0)
            return {};
        
        vector<string> ans;
        rec(digits, 0, len - 1, "", ans);
        
        return ans;
    }
};