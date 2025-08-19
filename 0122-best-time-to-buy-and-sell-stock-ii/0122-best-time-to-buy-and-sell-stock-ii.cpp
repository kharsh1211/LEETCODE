class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
        int ans=0;
        int start=price[0];

        for(int i=1;i<n;i++){
            if(start<price[i]){
                ans+=price[i]-start;
            }
            start=price[i];
        }
        return ans;



    }
};