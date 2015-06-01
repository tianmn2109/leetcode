class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        int *x = new int[n];
        memset(x, 0, n);
        backTrace(x, 0, n, sum);
        return sum;
    }
    void backTrace(int x[], int k, int n, int &sum) {
        if (k == n) {
            sum ++;
            return ;
        }
        for (int i = 0; i < n; i ++) {
            if (place(x, k, i)) {
                x[k] = i;
                backTrace(x, k + 1, n, sum);
                x[k] = 0;
            }
        }
    }
    bool place(int x[], int k, int pos) {
        for (int i = 0; i < k; i ++) {
            if (x[i] == pos || abs(i - k) == abs(x[i] - pos))
                return false;
        }
        return true;
    }
};
