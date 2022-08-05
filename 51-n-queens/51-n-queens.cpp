class Solution {
public:
    bool canPlace(vector<string> &board, int r, int c){
        for(int i=r-1;i>=0;i--)
            if(board[i][c] == 'Q')
                return false;
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
            if(board[i][j] == 'Q')
                return false;
        for(int i=r-1,j=c+1;i>=0 && j<board.size();i--,j++)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    void backtrack(vector<string> &board,vector<vector<string>> &ans, int r){
        if(r == board.size()){
            ans.push_back(board);
            return;
        }
        for(int c=0;c<board.size();c++){
            if(canPlace(board,r,c)){
                board[r][c] = 'Q';
                backtrack(board,ans,r+1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        backtrack(board,ans,0);
        return ans;
    }
};