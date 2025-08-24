class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,vector<int>&temp,int idx,int n){
        ans.push_back(temp);
        
         for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i + 1, n);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());

        solve(nums,temp,0,n);

        return ans;

    }
};