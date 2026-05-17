class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { backtrack(board); }

private:
    bool backtrack(vector<vector<char>>& board) {
        // Find next empty cell
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // Try numbers 1-9
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValidPlacement(board, i, j, num)) {
                            board[i][j] = num;

                            // Recursively try to solve
                            if (backtrack(board)) {
                                return true;
                            }

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }
                    // No valid number found, trigger backtracking
                    return false;
                }
            }
        }
        // No empty cells found, puzzle is solved
        return true;
    }

    bool isValidPlacement(vector<vector<char>>& board, int row, int col,
                          char num) {
        // Check row for duplicate
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) {
                return false;
            }
        }

        // Check column for duplicate
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // Check 3x3 sub-box for duplicate
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }
};
