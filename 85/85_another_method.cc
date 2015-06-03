class Solution {
public:
    int maxP(vector<int> num) {
        stack<int> stk;
        num.push_back(0);
        int maxVal = 0;
        for (int i = 0; i < num.size();) {
            if (stk.empty() || num[stk.top()] <= num[i]) {
                stk.push(i ++);
            }
            else {
                int temp = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxVal = max(maxVal, num[temp] * width);
            }
        }
        return maxVal;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int retMax = 0;
        vector<int> v(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++)
                v[j] = matrix[i][j] == '0' ? 0 : v[j] + 1;
            int tempMax = maxP(v);
            retMax = max(retMax, tempMax);
        }
        return retMax;
    }
};