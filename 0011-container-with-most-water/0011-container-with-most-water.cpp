class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxa=INT_MIN;
        int l=0;
        int r=n-1;

        while(l<r){
            maxa=max(maxa,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxa;        
    }
};