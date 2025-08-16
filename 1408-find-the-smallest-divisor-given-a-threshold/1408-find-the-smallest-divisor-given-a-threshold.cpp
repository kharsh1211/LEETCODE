class Solution {
public:
    bool check(vector<int>& nums, int threshold, int mid){
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0){
                count+=nums[i]/mid;
            }
            else{
                count+=nums[i]/mid + 1;
            }
        }
        return count<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};