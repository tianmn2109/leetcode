class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size()));
        int maxVal = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            if (dp[i][0] == 1)
                maxVal = 1;
        }
        for (int i = 0; i < matrix[0].size(); i ++) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            if (dp[0][i] == 1)
                maxVal = 1;
        }
        for (int i = 1; i < matrix.size(); i ++)
            for (int j = 1; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    int temp = min(dp[i - 1][j], dp[i][j - 1]);
                    if (temp == 0)
                        dp[i][j] = 1;
                    else 
                        dp[i][j] = matrix[i - temp][j - temp] == '1' ? temp + 1: temp;
                }
                maxVal = max(maxVal, dp[i][j]);
            }
        return maxVal * maxVal;
    }
};