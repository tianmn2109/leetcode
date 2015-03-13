/*
 * importane: considering the condition that the matrix is empty.
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int left = 0;
        int top = 0;
        vector<int> v;
        int bottom = matrix.size() - 1;       
        if (bottom < 0)                     //*******************//
            return v;

        int right = matrix[0].size() - 1; 
        if (right < 0)                     //******************//
            return v;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i ++)
                v.push_back(matrix[top][i]);
            for (int i = top; i < bottom; i ++)
                v.push_back(matrix[i][right]);
            for (int i = right; i > left; i --)
                v.push_back(matrix[bottom][i]);
            for (int i = bottom; i > top; i --)
                v.push_back(matrix[i][left]);
            left ++;
            top ++;
            right --;
            bottom --;
        }
        if (left < right && top == bottom) {
            for (int i = left; i <= right; i ++)
                v.push_back(matrix[top][i]);
        }
        if (top < bottom && left == right) {
            for (int i = top; i <= bottom; i ++)
                v.push_back(matrix[i][left]);
        }
        if (top == bottom && left == right)
            v.push_back(matrix[top][left]);
        return v;
    }
};
