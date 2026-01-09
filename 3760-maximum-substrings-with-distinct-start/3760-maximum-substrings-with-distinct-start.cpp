class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        unordered_set<int>st;
        for(auto &i:s){
            st.insert(i);
        }    
        return st.size();
    }
};