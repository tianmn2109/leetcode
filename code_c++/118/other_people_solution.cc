// 1
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret(numRows, vector<int>());
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<=i; j++) {
                ret[i].push_back(j == 0 ? 1 : j == i ? 1 : ret[i-1][j-1] + ret[i-1][j]);
            }
        }
        return ret;
    }
};

// 2
 vector<vector<int> > generate(int numRows) {
    vector<vector<int> > vvi;
    if (numRows<=0) return vvi;
    for (int i=1; i<=numRows; i++) {
        vector<int> vi(i, 1);
        for (int j=1; j<i-1; j++) vi[j] = vvi[i-2][j-1]+vvi[i-2][j];
        vvi.push_back(vi);
    }
    return vvi;
}
