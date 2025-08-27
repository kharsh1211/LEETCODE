class Solution {
public:
    vector<int>temp;
    map<int, int>mp;
    vector<vector<int>>ans;
    void solve(vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(auto &i:mp){
            if(i.second!=0){
                mp[i.first]--;
                temp.push_back(i.first);
                solve(nums);
                temp.pop_back();
                mp[i.first]++;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        solve(nums);
        return ans;  
    }
};