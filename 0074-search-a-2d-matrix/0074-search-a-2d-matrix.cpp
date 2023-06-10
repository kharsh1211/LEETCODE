class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int start=0;
        int end=m*n-1;
        
        while(start<=end){
            
            int mid_idx=(end-start)/2 + start;
            int mid_val=matrix[mid_idx/n][mid_idx%n];
            
            if(mid_val==target)
                return true;
            else if(mid_val>target)
                end=mid_idx-1;
            else
                start=mid_idx+1;
        }
        return false;
    }
};