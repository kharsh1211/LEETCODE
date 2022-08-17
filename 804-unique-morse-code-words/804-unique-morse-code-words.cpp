class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> ans;

        for(int i = 0; i < words.size();i++){
            string s = words[i]; 
            string temp = ""; 

            for(int j= 0 ;j < s.length(); j++){
                int e = s[j] - 'a'; 
                temp += morse[e];
            }
            ans.insert(temp); 
        }
        return ans.size(); 
    }
     
};