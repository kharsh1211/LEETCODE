class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();
        long long ans=0;
        for(char i='a';i<='z';i++){
            int last=-1;
            long long total=1LL*n*(n+1)/2;
            for(int j=0;j<n;j++){
                if(s[j]==i){
                    int len=j-last-1;
                    total-=1LL*len*(len+1)/2;
                    last=j;
                }
            }
            int x=n-last-1;
            total-=1LL*x*(x+1)/2;
            ans+=total;
        }  
        return ans;  
    }
};