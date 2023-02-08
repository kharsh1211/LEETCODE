class Solution {
public:
    int jump(vector<int>& nums) {
        int i,sum=0,j=nums[0],curr=0;
        int n=nums.size();
        for(i=0;i<n-1;i++){
            j=max(j,nums[i]+i);
            if(i==curr){
                curr=j;
                sum++;
            }
        }
        return sum;
    }
};