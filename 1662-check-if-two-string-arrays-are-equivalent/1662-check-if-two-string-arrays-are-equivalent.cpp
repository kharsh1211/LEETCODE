class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        
        string w1="";
        string w2="";
        
        for(int i=0;i<n;i++){
            w1=w1+word1[i];
        }
        
        for(int i=0;i<m;i++){
            w2=w2+word2[i];
        }
        
        if(w1==w2)
            return true;
        else
            return false;
    }
};