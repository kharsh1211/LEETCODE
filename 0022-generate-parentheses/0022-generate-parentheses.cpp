class Solution {
public:
    vector<string>ans;
    bool isValid(const string &a) {
        stack<char> st;
        for (char c : a) {
            if (c == '(') st.push(c);
            else {
                if (st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void solve(string &s,int n){
        if(s.size()==2*n){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(s,n);
        s.pop_back();

        s.push_back(')');
        solve(s,n);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s,n); 
        return ans;       
    }
};