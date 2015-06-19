// 1
  Solution {  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        --n; --m;
        while(n > 0 && matrix[n - 1][m] >= target) --n;
        while(m > 0 && matrix[n][m - 1] >= target) --m;
        return (matrix[n][m] == target);
    }
};
