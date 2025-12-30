class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i=0;i<n;i++){
            mp1[s1[i]]++;
        }
        int l=0;
        int r=0;

        while(r<m){
            mp2[s2[r]]++;
            if((r-l+1)>n){
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0) mp2.erase(s2[l]);
                l++;
            }
            if((r-l+1)==n && mp1==mp2) return true;
            r++;
        }
        return false;
        
    }
};