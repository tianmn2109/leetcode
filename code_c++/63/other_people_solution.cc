// 1
just use dp to find the answer , if there is a obstacle at (i,j), then dp[i][j] = 0. time is O(nm) , space is O(nm) . here is my code:

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};



// 2 
Well, this problem is similar to Unique Paths. The introduction of obstacles only changes the boundary conditions and make some points unreachable (simply set to 0).

Denote the number of paths to arrive at point (i, j) to be P[i][j], the state equation is P[i][j] = P[i - 1][j] + P[i][j - 1] if obstacleGrid[i][j] != 1 and 0 otherwise.

Now let's finish the boundary conditions. In the Unique Paths problem, we initialize P[0][j] = 1, P[i][0] = 1 for all valid i, j. Now, due to obstacles, some boundary points are no longer reachable and need to be initialized to 0. For example, if obstacleGrid is like [0, 0, 1, 0, 0], then the last three points are not reachable and need to be initialized to be 0. The result is [1, 1, 0, 0, 0].

Now we can write down the following (unoptimized) code.

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > path(m, vector<int> (n, 0));
        for (int j = 0; j < n; j++)
            if (obstacleGrid[0][j] != 1) path[0][j] = 1;
            else break;
        for (int i = 1; i < m; i++)
            if (obstacleGrid[i][0] != 1) path[i][0] = 1;
            else break;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (obstacleGrid[i][j] != 1)
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }

Well, the code is accepted but it has some obvious redundancy. There are two major concerns:

    Each time when we update path[i][j], we only need path[i - 1][j] (at the same column) and path[i][j - 1] (at the previous left column), so it is unnecessary to maintain the full m*n matrix. Maintaining two columns are enough.
    There are some cases that the loop can be terminated earlier. Suppose obstacleGrid = [[0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0]], then we can see that it is impossible to reach the right-down corner. Suppose we update path column by column, then after updating the second column, the fact is obvious since the number of paths to reach each element in the current column are all 0.

Taken these into considerations, we write down the following optimized code.

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] != 1)
                pre[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j] != 1) {
                cur[0] = pre[0];
                if (cur[0]) flag = true;
            }
            for (int i = 1; i < m; i++) {
                if (obstacleGrid[i][j] != 1) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
            }
            if (!flag) return 0;
            pre = cur;
            fill(cur.begin(), cur.end(), 0);
        }
        return pre[m - 1];
    }

Further inspecting the above code, keeping two vectors only serve for the purpose of recovering pre[i], which is simply cur[i] before its update. So we can use only one vector and the space is further optimized.

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> cur(m, 0);
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] != 1)
            cur[i] = 1;
        else break;
    }
    for (int j = 1; j < n; j++) {
        bool flag = false;
        if (obstacleGrid[0][j] == 1)
            cur[0] = 0;
        else flag = true;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][j] != 1) {
                cur[i] += cur[i - 1];
                if (cur[i]) flag = true;
            }
            else cur[i] = 0;
        }
        if (!flag) return 0;
    }
    return cur[m - 1];
}

A final note, the introduction of early terminating in the above codes seems to give no difference. Well, it may due to that the OJ does not have too many cases like this:

[0,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ..., 0]

[0,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ..., 0]

[0,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ..., 0]

...

[0,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ..., 0]

