class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        for(int i=0;i<=high/2;i++){
            if((2*i+1)>=low && (2*i+1)<=high)
                count++;
        }
        return count;
    }
};