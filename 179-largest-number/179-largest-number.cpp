class Solution {
public:
    static bool cmp(string &a,string &b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>q;
        
        for(auto ele:nums){
           q.push_back(to_string(ele)); 
        }
        
        sort(q.begin(),q.end(),cmp);
        string ans="";
        
        for(auto ele:q){
            ans+=ele;
        }
        
        if(ans[0]=='0')return "0";
        
        return ans;
        
    }
};