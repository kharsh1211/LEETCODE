class Solution {
public:
    bool check(vector<int>&x,int k){
        int n=x.size();
        for(int i=1;i<n;i++){
            if((x[i]-x[i-1])<=k) return true;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }    
        for(auto &x:mp){
            if(x.second.size()>1){
                if(check(x.second,k)) return true;
            }
        }
        return false;
    }
};