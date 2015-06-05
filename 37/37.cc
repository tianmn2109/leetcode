class Solution {
public:
    void solveSudoku(vector<vector<char> > & board) {
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char> > &board, int row, int col) {
        if (row == 9 && col == 0)
            return true;
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i ++) {
                board[row][col] = '0' + i;
                if (check(board, row, col)) {
                    int nextRow = row + (col + 1) / 9;
                    int nextCol = (col + 1) % 9;
                    if (solve(board, nextRow, nextCol))
                        return true;
                }
                board[row][col] = '.';
            }
        }
        else {
            row = row + (col + 1) / 9;
            col = (col + 1) % 9;
            return solve(board, row, col);
        }
        return false;
    }
    bool check(vector<vector<char> > &board, int row, int col) {
        for (int i = 0 ;i < 9; i ++)
            if (i != row && (board[i][col] == board[row][col]))
                return false;
        for (int i = 0; i < 9; i ++)
            if (i != col && (board[row][i] == board[row][col]))
                return false;
        int subRow = row / 3 * 3;
        int subCol = col / 3 * 3;
        for (int i = subRow; i < subRow + 3; i ++)
            for (int j = subCol; j < subCol + 3; j ++)
                if (!(i == row && j == col) && (board[i][j] == board[row][col]))
                    return false;
        return true;
    }
};
