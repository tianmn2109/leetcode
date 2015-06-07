class Solution {
public:
    vector<vector<int> > ret;
    void combinationKsum(vector<int> v, int left, int k, int n) {
        if (left > n)
            return ;
        if (k == 1) {
                if (left <= n && n <= 9) {
                    v.push_back(n);
                    ret.push_back(v);
                }
                return ;
        }
        for (int i = left; i <= n && i <= 9; i ++) {
            v.push_back(i);
            combinationKsum(v, i + 1, k - 1, n - i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        combinationKsum(v, 1, k, n);
        return ret;
    }
};
