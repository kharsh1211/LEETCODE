class Solution {
public:
    int check(int mid,vector<int>& nums){
        int n=nums.size();
        if(nums[mid]<=nums[n-1]) return 1;
        return 0;
    }
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        int l = start, r = end;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int mini=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums)==1){
                mini=mid;
                r=mid-1;
            }
            else l=mid+1;
        } 
        if (target >= nums[mini] && target <= nums[n-1]) {
            return binarySearch(nums, mini, n - 1, target);
        } else {
            return binarySearch(nums, 0, mini - 1, target);
        }
          
    }
};