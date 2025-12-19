class Solution {
public:
    int check(int mid,vector<int>& nums){
        if(nums[mid]<=nums[nums.size()-1]) return 1;
        return 0;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int r=n-1,l=0;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums)==1){
                ans=nums[mid];
                r=mid-1;
            }
            else l=mid+1;
        }    
        return ans;
    }
};