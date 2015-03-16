class Solution {
public:

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m * n - 1;

        while (start <= end) {
            int middle = (start + end) / 2;
            int i = middle / n;
            int j = middle % n;

            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] > target) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }
        return false;
    }
};
