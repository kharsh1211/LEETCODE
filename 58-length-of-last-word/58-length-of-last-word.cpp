class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int i = s.size()-1;
        while(i>=0){
            if(s[i]!=' ')break;
            i--;
        }
        
        while(i>=0){
            if(s[i]==' ')break;
            count++;
            i--;
        }
        return count;    
    }
};