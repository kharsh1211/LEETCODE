class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN,pro=1,backpro=1;
        int n=nums.size();
     
        for(int i=0;i<nums.size();i++)
        {
            pro=pro*nums[i];
            backpro=backpro*nums[n-1-i];
            maxi=max(maxi,max(pro,backpro));
            if(pro==0)
                pro=1;
            if( backpro==0)
                backpro=1;
        }
        return maxi;
    }
};