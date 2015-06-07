class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0)
            return ret;
        ret.push_back(vector<int>(1,1));
        for (int i = 2; i <= numRows; i ++) {
            vector<int> v(i);
            v[0] = 1;
            v[i - 1] = 1;
            for (int j = 1; j < i - 1; j ++)
                v[j] = ret[i - 2][j - 1] + ret[i - 2][j];
            ret.push_back(v);;
        }
        return ret;
    }
};
