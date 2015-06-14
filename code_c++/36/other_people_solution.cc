// 1
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int N = 9;
        int VAL_TO_PRIME[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        int rows[N]; 
        int cols[N]; 
        int boxes[N]; 

        for(int i = 0; i < N; ++i) {
            rows[i] = cols[i] = boxes[i] = 1;
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == '.') continue;
                int d = VAL_TO_PRIME[grid[i][j] - 1 - '0'];
                if(rows[i] % d == 0 || cols[j] % d == 0 || boxes[i - i % 3 + j / 3] % d == 0){
                    return false;
                }
                rows[i] *= d;
                cols[j] *= d;
                boxes[i - i % 3 + j / 3] *= d;
            }
        }
        return true;
    }
};

// 2
Three flags are used to check whether a number appear.

used1: check each row

used2: check each column

used3: check each sub-boxes

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
    }
};




// 3
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
         vector<vector<int>> bucket(3, vector<int>(9, 0));
         for (int i = 0; i < 9; i++)
         {
             for (int j = 0; j < 9; j++)
             {
                 if (board[i][j] != '.' && ++bucket[0][board[i][j] - '1'] > 1) return false;
                 if (board[j][i] != '.' && ++bucket[1][board[j][i] - '1'] > 1) return false;
                 int v = j%3 + 3*(i%3);
                 int h = j/3 + 3*(i/3);
                 if (board[v][h] != '.' && ++bucket[2][board[v][h] - '1'] > 1) return false;
             }
             bucket = vector<vector<int>>(3, vector<int>(9, 0));
         }
    }
};


