class Solution {
public:
int minSwaps(vector<int>a)
{
int n=a.size();
if(n==1 and a[0]==0) return 0;

    vector<int> a2;
    for(int i=0;i<n;i++) a2.push_back(a[i]);
    for(int i=0;i<n;i++) a2.push_back(a[i]);
    
    int ans=INT_MAX,ones=0;

    for(int i=0;i<n;i++) if(a[i]==1) ones++;
    if(ones==n) return 0;
    if(ones==0) return 0;

    int k=ones;

    
    int winOnes=0;
    for(int i=0;i<k;i++)
    {
        if(a2[i]==1) winOnes++;
    }
    //swaps
    ans=min(ans,(k-winOnes)); 

    for(int i=k;i<2*n;i++)
    {
        if(a2[i]==1)   winOnes++;
        if(a2[i-k]==1) winOnes--;
        ans=min(ans,(k-winOnes));
    }

    return ans;
}
};