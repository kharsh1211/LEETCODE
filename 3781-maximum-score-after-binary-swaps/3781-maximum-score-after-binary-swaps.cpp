class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n=nums.size();
        priority_queue<int>pq;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') pq.push(nums[i]);
            else if(s[i]=='1'){
                pq.push(nums[i]);
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};