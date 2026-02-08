class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int>st;
        vector<int>ans;
        int i=0,j=0;
        while(j<n){
            st.insert(nums[j]);
            if((j-i+1)>k){
                st.erase(st.find(nums[i]));
                i++;
            }
            if((j-i+1)==k) ans.push_back(*st.rbegin());
            j++;
        }  
        return ans;  
    }
};