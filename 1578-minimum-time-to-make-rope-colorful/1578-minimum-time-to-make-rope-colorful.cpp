class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int output = 0;
        int n = neededTime.size();
        int count, sum, maxval;
        
        for(int i=0; i<n; ) {
            count = 0, sum = 0, maxval = 0;
            char color = colors[i];
            while(colors[i] == color) {
                count += 1;
                sum += neededTime[i];
                maxval = max(maxval, neededTime[i]);
                i++;
            }
            if(count > 1) {
                sum -= maxval;
                output += sum;
            }
        }
        
        return output;
    }
};