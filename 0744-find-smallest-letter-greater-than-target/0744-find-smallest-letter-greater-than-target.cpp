class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l=0;
        int r=n-1;
        
        if(target<letters[0])
            return letters[0];
        
        else if(target >=letters[n-1])
            return letters[0];
        
        char ans;
        
        while(l<=r){
            int mid=(l+r)/2;
            
            if(letters[mid]>target){
                ans=letters[mid];
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};