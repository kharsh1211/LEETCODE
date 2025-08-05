class Solution {
public:
    int check(vector<int>& nums,int mid){
        if(nums[mid]<=nums[nums.size()-1]){
            return 1;
        }
        else{
            return 0;
        }
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,mid)==1){
                ans=nums[mid];
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        } 
        return ans;   
    }
};