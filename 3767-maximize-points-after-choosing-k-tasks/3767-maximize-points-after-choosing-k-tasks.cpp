class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        vector<int>diff;
        long long ans=0;
        for(int i=0;i<n;i++){
            diff.push_back(technique1[i]-technique2[i]);
            ans+=technique2[i];
        }
        sort(diff.rbegin(),diff.rend());
        for(int i=0;i<k;i++){
            ans+=diff[i];
        }
        for(int i=k;i<n;i++){
            if(diff[i]>0) ans+=diff[i];
        }
        return ans;
    }
};