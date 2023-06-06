class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        int d;
        sort(arr.begin(),arr.end());
        
        int d1=arr[1]-arr[0];
        for(int i=2;i<n;i++){
            int d=arr[i]-arr[i-1];
            if(d != d1)
                return false;
        }
        return true;
    }
};