class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit= INT_MIN;
        int minEl= INT_MAX;
        int n= prices.size();
        
        for(int i=0;i<n;i++){
             minEl= min(minEl,prices[i]);
             profit= max(profit, prices[i]-minEl);
        }
        return profit;    
    }
};