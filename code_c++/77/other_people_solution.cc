// 1
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > rslt;
        vector<int> path(k, 0);
        combine(n, k, rslt, path);
        return rslt;
    }
private:
    void combine(int n, int k, vector<vector<int> > &rslt, vector<int> &path) {
        if (k == 0) {
            rslt.push_back(path);
            return;
        }
        for (int i = n; i >= 1; i--) {
            path[k - 1] = i;
            combine(i - 1, k - 1, rslt, path);
        }
    }
};




