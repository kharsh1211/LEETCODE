class Solution {
public:
    vector<string> v = { "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void rec(string &digits,int curr_inx,int last_inx, string s, vector<string> &sol)
    {
        string curr = v[digits[curr_inx] - 49];
        
        for(int i = 0; i < curr.size(); i++)
        {
            if(curr_inx == last_inx)
                sol.push_back(s + curr[i]);
            else
                rec(digits, curr_inx + 1, last_inx, s + curr[i], sol);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        int len = digits.size();
        if(len == 0)
            return {};
        
        vector<string> sol;
        rec(digits, 0, len - 1, "", sol);
        
        return sol;
    }
};