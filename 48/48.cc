/*
 * rotate from the outside to the inside.
 */

class Solution {
public:
    void rotateSingle(vector<vector<int> > &matrix, int left, int top, int right, int down) {
        for (int i = 0; i < right - left; i ++)
            {
                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[down - i][left];
                matrix[down - i][left] = matrix[down][right - i];
                matrix[down][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }
    }

    void rotate(vector<vector<int> > &matrix) {

        if (matrix.size() == 0)
            return;

        int left = 0;
        int top = 0;
        int down = matrix.size() - 1;
        int right = matrix.size() - 1;

        while (left < right && top < down) {
            rotateSingle(matrix, left, top, right, down);
            left ++;
            top ++;
            right --;
            down --;
        }
    }
};
