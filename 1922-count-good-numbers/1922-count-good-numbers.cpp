class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    
    ll power(int x, ll y)
    {
        ll temp;
        if (y == 0)
            return 1;
        temp = power(x, y / 2);
        if (y % 2 == 0)
            return (1ll*temp * temp)%mod;
        else
            return (((1ll*x* temp)%mod) * temp)%mod;
    }
    
    
    
    
    int countGoodNumbers(long long n) {
        ll a,b=power(4,n/2);
        ll ans;
        if(n%2==0)
           a=power(5,n/2);
        else
           a=power(5,n/2 + 1);
        
        return (a*b)%mod;
    }
    
};