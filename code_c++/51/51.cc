class Solution {
public:
    vector<vector<string> > ret;
    vector<vector<string> > solveNQueens(int n) {
        int *a = new int[n];
        memset(a, 0, n);
        backTrace(a, 0, n);
        return ret;
    }
    void backTrace(int a[], int k, int n) {
        if (k == n) {
            string s = "";
            for (int i = 0; i < n; i ++)
                s += ".";
            vector<string> v(n, s);
            for (int i = 0; i < n; i ++)
                v[i][a[i]] = 'Q';
            ret.push_back(v);
            return ;
        }
        for (int i = 0; i < n; i ++) {
            if (place(a, k, i)) {
                a[k] = i;
                backTrace(a, k + 1, n);
                a[k] = 0;
            }
        }
    }
    bool place(int a[], int k, int pos) {
        for (int i = 0; i < k; i ++) {
            if (a[i] == pos || abs(i - k) == abs(a[i] - pos))
                return false;
        }
        return true;
    }
};
