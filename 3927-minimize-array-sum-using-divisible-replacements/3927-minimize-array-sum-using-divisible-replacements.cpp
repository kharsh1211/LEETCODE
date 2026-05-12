class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int mini=nums[i];
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(s.count(j)){
                        mini=min(mini,j);
                    }
                    if(s.count(nums[i] / j)) {
                        mini = min(mini, nums[i] / j);
                    }
                }
            }
            nums[i]=mini;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
        }
        return ans;
    }
};