class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};         int n=s.size();
        int ans=m[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                ans-=m[s[i]];
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
                ans-=m[s[i]];
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                ans-=m[s[i]];
            else
                ans+=m[s[i]];
            
        }
        return ans;
    }
};