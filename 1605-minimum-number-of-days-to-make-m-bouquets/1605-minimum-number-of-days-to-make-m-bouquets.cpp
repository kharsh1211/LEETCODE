class Solution {
public:
    bool check(int mid,vector<int>& bloomDay,int m,int k){
        int n=bloomDay.size();
        int count=0;
        int adj=0;
        
        for(auto &x:bloomDay){
            if(x<=mid){
                adj++;
                if(adj==k){
                    count++;
                    adj=0;
                }
            }
            else{
                adj=0;
            }
        }
       
        return count>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,bloomDay,m,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};