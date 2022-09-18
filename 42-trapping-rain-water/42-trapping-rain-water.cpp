class Solution {
public:
    int trap(vector<int>& height){
        int n =height.size();
        int l[n],r[n];
        int ma,mi;
        int s=0;
        ma=l[0]=height[0];
        mi=r[n-1]=height[n-1];
        for(int i=0;i<n;i++){
            if(height[i]>ma)
                ma=height[i];
            l[i]=ma;
        }
        for(int i=n-2;i>=0;i--){
            if(height[i]>mi)
                mi=height[i];
            r[i]=mi;
        }
        for(int i=0;i<n;i++){
            s=s+min(l[i],r[i])-height[i];
        }
        return s;
    }
};