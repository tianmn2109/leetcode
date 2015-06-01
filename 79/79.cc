class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int> > record(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i ++)
            for (int j = 0; j < board[0].size(); j ++) {
                if (backTrace(record, board, i, j, word, 0))
                    return true;
            }
        return false;
    }
    bool backTrace(vector<vector<int> > &record, vector<vector<char> >& board, int i, int j, string &word, int start) {
        if (word[start] != board[i][j])
            return false;
        record[i][j] = 1;
        if (start == word.size() - 1)
            return true;
        if (i - 1 >= 0 && record[i - 1][j] == 0) {      // up
            if (backTrace(record, board, i - 1, j, word, start + 1))
                return true;
        }
        if (i + 1 < board.size() && record[i + 1][j] == 0) {     // down
            if (backTrace(record, board, i + 1, j, word, start + 1))
                return true;
        }
        if (j - 1 >= 0 && record[i][j - 1] == 0) {       // left
            if (backTrace(record, board, i, j - 1, word, start + 1))
                return true;
        }
        if (j + 1 < board[0].size() && record[i][j + 1] == 0) {      // right
            if (backTrace(record, board, i, j + 1, word, start  +1))
                return true;
        }
        record[i][j] = 0;
        return false;
    }
};
