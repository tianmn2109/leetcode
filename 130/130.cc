class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
            return ;
        for (int i = 0; i< board.size(); i ++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][board[0].size() - 1] == 'O')
                bfs(board, i, board[0].size() - 1);
        }
        for (int i = 0; i < board[0].size(); i ++) {
            if (board[0][i] == 'O')
                bfs(board, 0, i);
            if (board[board.size() - 1][i] == 'O')
                bfs(board, board.size() - 1, i);
        }
        for (int i = 0; i < board.size(); i ++)
            for (int j = 0; j < board[0].size(); j ++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'K')
                    board[i][j] = 'O';
    }
    void bfs(vector<vector<char> > &board, int iPos, int jPos) {
        queue<pair<int, int> > q;
        q.push(make_pair(iPos, jPos));
        board[iPos][jPos] = 'K';
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second;
            if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                q.push(make_pair(i - 1, j));
                board[i - 1][j] = 'K';
            }
            if (i + 1 < board.size() && board[i + 1][j] == 'O') {
                q.push(make_pair(i + 1, j));
                board[i + 1][j] = 'K';
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                q.push(make_pair(i, j - 1));
                board[i][j - 1] = 'K';
            }
            if (j + 1 < board[0].size() && board[i][j + 1] == 'O') {
                q.push(make_pair(i, j + 1));
                board[i][j + 1] = 'K';
            }
        }
    }
};
