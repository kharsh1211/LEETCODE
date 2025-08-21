class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,int n,vector<int>temp,int idx){
        if(temp.size()>k) return;
        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<=9;i++){
            temp.push_back(i);
            solve(k,n-i,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int sum=0;
        int idx;
        solve(k,n,temp,1);
        return ans;
    }
};