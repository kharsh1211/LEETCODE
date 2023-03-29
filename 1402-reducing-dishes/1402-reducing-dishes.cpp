class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        int sum=0,ans=0;
        for(int i=0;i<satisfaction.size();i++){
            if(sum+satisfaction[i]>0){
                ans+=sum+satisfaction[i];
                sum=sum+satisfaction[i];
            }
        }
        return ans;
    }
};