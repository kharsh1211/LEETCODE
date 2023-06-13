class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        bool flag;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                flag=true;
                for(int k=0;k<n;k++){
                    if(grid[i][k]==grid[k][j])
                        continue;
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                    count=count+1;
            }
        }
        
        return count; 
    }
};