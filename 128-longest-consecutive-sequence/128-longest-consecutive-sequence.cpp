class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1,res=1;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                continue;
            if(nums[i+1]==nums[i]+1)
                count=count+1;
            else
                count=1;
            if(count>res) 
                res=count;
        }
        return res;
    }
};