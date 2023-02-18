class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeintervals;
        if(intervals.size()==0)
            return mergeintervals;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[0][1])
                intervals[0][1]=max(intervals[i][1],intervals[0][1]);
            else{
                mergeintervals.push_back(intervals[0]);
                intervals[0]=intervals[i];
            }
        }
        mergeintervals.push_back(intervals[0]);
        return mergeintervals;
    }
};