class Solution {
public:
    bool yes(string a,string b){    
        int j=0;
        sort(b.begin(),b.end());
        for(int i=0;i<b.size();i++){
            if(b[i]==a[j])
                j++;
        }
       if(j==a.size())
           return true;
        return false;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>v;
        string ans;
        vector<int>temp(26,0);
        
        for(int i=0;i<words2.size();i++){  
           vector<int>nums(26,0);
            for(int j=0;j<words2[i].size();j++){
                nums[words2[i][j]-'a']++;
            }
            for(int i=0;i<26;i++){
                temp[i]=max(temp[i],nums[i]);
            }
        }
        
        for(int i=0;i<26;i++){
            for(int j=0;j<temp[i];j++){
                ans.push_back(i+'a');        
            }
        }
        cout<<ans<<" ";
          sort(ans.begin(),ans.end());
           for(int i=0;i<words1.size();i++){
               if(yes(ans,words1[i]))
                   v.push_back(words1[i]);
            }
        return v;
    }
};