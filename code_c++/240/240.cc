class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int j = matrix[0].size() - 1;
        int i = 0;
        while (j >= 0 && i < matrix.size()) {
            while (j >= 0 && matrix[i][j] > target)
                j --;
            if (j < 0)
                return false;
            while (i < matrix.size() && matrix[i][j] < target)
                i ++;
            if (i == matrix.size())
                return false;
            if (matrix[i][j] == target)
                return true;
        }
        return false;
    }
};
