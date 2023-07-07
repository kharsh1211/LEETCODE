class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,count=0;
        int ans=INT_MIN;
        int n=answerKey.size();
        
        while(j<n){
            if(answerKey[j]=='T')
                count++;
            while(count>k){
                if(answerKey[i]=='T')
                    count--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
        }
        
        j=0,i=0,count=0;
        while(j<n){
            if(answerKey[j]=='F')
                count++;
            while(count>k){
                if(answerKey[i]=='F')
                    count--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
        }
        
        return ans;
    }
};