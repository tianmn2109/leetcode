/*
 */
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int num = 1;
        vector<vector<int> > v(n, vector<int>(n));
        int left = 0;
        int top = 0;
        int right = n -1;
        int bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i < right; i ++)
                v[top][i] = num ++;
            for (int i = top; i < bottom; i ++)
                v[i][right] = num ++;
            for (int i = right; i > left; i --)
                v[bottom][i] = num ++;
            for (int i = bottom; i > top; i --)
                v[i][left] = num ++;

            if (left == right && top == bottom)
                v[left][top] = num ++;
            left ++;
            top ++;
            right --;
            bottom --;
        }
        return v;
    }
};
