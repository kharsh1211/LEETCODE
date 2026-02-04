class Solution {
public:
    int check(const vector<int>& filtered) {
        if (filtered.empty()) return 0;
        vector<int> lis;
        for (int x : filtered) {
            if(lis.empty()|| lis.back()<x) lis.push_back(x);
            else{
                auto it=lower_bound(lis.begin(),lis.end(),x);
                *it=x;
            }
        }
        return lis.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        for (int bit = 0; bit < 31; ++bit) {
            vector<int> filtered;
            for (int x : nums) {
                if ((x >> bit) & 1) {
                    filtered.push_back(x);
                }
            }
            res = max(res, check(filtered));
        }
        return res;
    }
};