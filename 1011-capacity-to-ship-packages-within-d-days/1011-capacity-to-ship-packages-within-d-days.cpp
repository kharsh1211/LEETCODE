class Solution {
public:
    bool check(vector<int>& weights, int days, int mid){
        int carry=0;
        int dcnt=1;
        for(int i=0;i<weights.size();i++){
            if(carry+weights[i]>mid) {
                dcnt++;
                carry=weights[i];
            }
            else{
                carry+=weights[i];
            }
        }
        return dcnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxw=*max_element(weights.begin(),weights.end());

        int l=maxw;
        int r=500*5*1e4;
        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(weights,days,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};