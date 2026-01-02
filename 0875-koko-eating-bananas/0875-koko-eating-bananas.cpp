class Solution {
public:
    bool check(int mid,vector<int>& piles, int h){
        int n=piles.size();
        int hcnt=0;
        for(int i=0;i<n;i++){
            hcnt+=piles[i]/mid;
            if(piles[i]%mid!=0) hcnt++;
        }
        return hcnt<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long l=1;
        long long r=0;
        for(int i=0;i<n;i++){
            r+=piles[i];
        }   
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,piles,h)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return (int)ans;
    }
};