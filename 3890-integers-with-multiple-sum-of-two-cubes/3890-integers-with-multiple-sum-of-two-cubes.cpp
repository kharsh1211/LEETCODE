class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int>mp;
        for(int i=1;i*i*i<n;i++){
            for(int j=i+1;j*j*j<n;j++){
                if((i*i*i+j*j*j)<=n) mp[i*i*i+j*j*j]++;
            }
        }    
        vector<int>ans;
        for(auto x:mp){
            if(x.second>1) ans.push_back(x.first);
        }
        return ans;
    }
};