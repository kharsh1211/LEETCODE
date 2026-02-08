class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        multiset<int>st;
        int i=0,j=0;    
        long long ans=0;
        while(j<n){
            st.insert(nums[j]);
            while(1LL*(*st.rbegin()-*st.begin())*(j-i+1)>k){
                st.erase(st.find(nums[i]));
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};