class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for (int i = 0; i < 9; i ++) {
           vector<int> row(9, 0);
           vector<int> col(9, 0);
           for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (row[board[i][j] - '1'] > 0)
                        return false;
                    else
                        row[board[i][j] - '1'] ++;
               }
               if (board[j][i] != '.') {
                   if (col[board[j][i] - '1'] > 0)
                        return false;
                    else
                        col[board[j][i] - '1'] ++; 
                }
           }
       }
           for (int i = 0; i < 9; i += 3)
                for (int j = 0; j < 9; j +=3) {
                    vector<int> f(9, 0);
                    for (int a = 0; a < 3; a ++)
                        for (int b = 0; b < 3; b ++) {
                            if (board[i + a][b + j] == '.')
                                continue;
                            if (f[board[i + a][j + b] - '1'] > 0)
                                return false;
                            else
                                f[board[i + a][b + j] - '1'] ++;
                        }
                }
            return true;
    }
};
