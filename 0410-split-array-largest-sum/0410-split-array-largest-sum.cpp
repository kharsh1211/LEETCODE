class Solution {
public:
    bool check(int mid,vector<int>& nums, int k){
        int n=nums.size();
        int subcnt=1;
        int temp=mid;
        for(int i=0;i<n;i++){
            if((temp-nums[i])<0) {
                subcnt++;
                temp=mid;
            }
            temp-=nums[i];
        }
        return subcnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=0;
        for(int i=0;i<n;i++){
            r+=nums[i];
        }  
        int ans=0;  
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};