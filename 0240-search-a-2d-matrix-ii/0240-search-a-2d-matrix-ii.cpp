class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        
        for(int i=0;i<m;i++){
            auto lower=lower_bound(matrix[i].begin(),matrix[i].end(),target);
            
            if(lower!=matrix[i].end() && *lower==target){
                return true;
            }
        }
        return false;
    }
};