class Solution {
public:
    void solve(vector<int>& candidates, int target,int idx,int n,vector<vector<int>>&ans,vector<int>& temp){
        if (target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,n,ans,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates,target,0,n,ans,temp);

        return ans;


    }
};