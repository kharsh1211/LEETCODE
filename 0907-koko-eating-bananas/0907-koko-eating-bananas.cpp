class Solution {
public:
    long long compute(vector<int>& piles, int h,int mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
                ans+=piles[i]/mid;
            }
            else{
                ans+=piles[i]/mid+1;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }

        int l=1;
        int r=maxPile;
        long long mini=LONG_MAX;

        while(l<=r){
            int mid=l+(r-l)/2;
            long long c=compute(piles,h,mid);
            if(c<=h){
                mini=min(mini,1LL*mid);
                r=mid-1;
            }
            else if(c>h){
                l=mid+1;
            }

        }
        return (int)mini;
    }
};