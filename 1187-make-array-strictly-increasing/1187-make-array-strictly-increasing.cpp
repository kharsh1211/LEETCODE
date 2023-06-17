class Solution {
private:
    int helper(int idx, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp) {
        //Base case
        if(idx == arr1.size()) {
            return 0;
        }

        //Explore all paths;
        if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        int ans=1e9;

        //Replace
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(i < arr2.size()) {
            ans = min(ans,1 + helper(idx + 1, arr2[i], arr1, arr2, dp));            
        }

        //Not replace
        if(arr1[idx] > prev) {
            ans = min(ans,helper(idx + 1, arr1[idx], arr1, arr2, dp));
        }

        return dp[{idx, prev}] = ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int, int>, int> dp;
        sort(arr2.begin(), arr2.end());
        int ans = helper(0, -1, arr1, arr2, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};