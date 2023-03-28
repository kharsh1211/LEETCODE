class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1);
        return check(days,costs,0,dp); 
    }
    int check(vector<int>&d,vector<int>&c,int day,vector<int>&dp){
        if(day>=d.size()) 
            return 0;
        if(dp[day]!=0) 
            return dp[day];
        int d1=check(d,c,day+1,dp)+c[0];
        int i;
        for(i=day;i<d.size();i++){
            if(d[i]>=d[day]+7) 
                break;
        }
        int d7=check(d,c,i,dp)+c[1];
        for(i=day;i<d.size();i++){
            if(d[i]>=d[day]+30) 
                break;
        }
        int d30=check(d,c,i,dp)+c[2];
        return dp[day]=min({d1,d7,d30});
    }
};