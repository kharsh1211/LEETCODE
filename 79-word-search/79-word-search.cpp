class Solution {
public:
    string word;
    bool exist(vector<vector<char>>& grid, string word) {
        this->word = word;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == word[0]){
                    if (search(grid, i, j))
                        return true;
                }     
            }
        }
        return false;
    }
    bool search(vector<vector<char>> &grid, int i, int j, int k = 0){
        if(k >= word.size())
            return true;
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != word[k])
            return false;
        
        char temp = grid[i][j];
        
        grid[i][j] = '#';
        
        if(search(grid, i-1, j, k + 1)){
            return true;
        }
        if(search(grid, i, j-1, k + 1)){
            return true;
        }
        if(search(grid, i+1, j, k + 1)){
            return true;
        }
        if(search(grid, i, j+1, k + 1)){
            return true;
        }
        
        grid[i][j] = temp;
        
        return false;
    }
};