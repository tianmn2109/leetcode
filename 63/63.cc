class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 0)
            return 0;

        int n = obstacleGrid[0].size();
        if (n < 0)
            return 0;

        vector<vector<int> > v(m, vector<int>(n));
        for (int i = 0; i < m; i ++)
            if (obstacleGrid[i][0] == 1) {
                for (int k = i; k < m; k ++)
                    v[k][0] = 0;
                break;
            }
            else {
                v[i][0] = 1;
            }

        for (int i = 0;i < n; i ++)
            if (obstacleGrid[0][i] == 1) {
                for (int k = i; k < n; k ++)
                    v[0][k] = 0;
                break;
            }
            else {
                v[0][i] = 1;
            }
        for (int i = 1; i < m; i ++)
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 1)
                    v[i][j] = 0;
                else 
                    v[i][j] = v[i -1][j] + v[i][j - 1];
            }
            return v[m - 1][n  - 1];
    }
};
