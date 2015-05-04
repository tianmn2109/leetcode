class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > d(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i ++)
            d[i][0] = 1;
        for (int i  = 1; i <= t.size(); i ++)
            d[0][i] = 0;
        for (int i = 1; i <= s.size(); i ++)
            for (int j = 1; j <= t.size(); j ++) {
                if (s[i - 1] == t[j - 1])
                    d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
                else
                    d[i][j] = d[i - 1][j];
            }
        return d[s.size()][t.size()];
    }
};
