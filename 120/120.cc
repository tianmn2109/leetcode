class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];
        int n = triangle.size();
        vector<int> v((1 + n) * n/ 2, 0);
        v[0] = triangle[0][0];
        for (int i = 1; i < n; i ++) {
            v[(1 + i) * i / 2] = triangle[i][0] + v[i * (i - 1) / 2];
            for (int j = 1; j < i; j ++) {
                v[(1 + i) * i / 2 + j] = min(v[i * (i - 1) / 2 + j - 1], v[i * (i - 1) / 2 + j]) + triangle[i][j];
            }
            v[(1 + i) * (i + 2) / 2 - 1] = v[(1 + i) * i / 2 - 1] + triangle[i][i];
        }
        int start = (n - 1) * n / 2;
        int end = (n + 1) * n / 2;
        int minimum = v[start];
        for (int i = start + 1; i < end; i ++)
            if (v[i] < minimum)
                    minimum = v[i];
        return minimum;
    }
};
