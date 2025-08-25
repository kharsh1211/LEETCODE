class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    void solve(int n,int k,int idx){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++){
            if(find(temp.begin(),temp.end(),i)==temp.end()){
                temp.push_back(i);
                solve(n,k,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);  
        return ans;  
    }
};