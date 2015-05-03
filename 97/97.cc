class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool> > v(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        v[0][0] = true;
        for (int i = 1; i <= s1.size(); i ++)
            v[i][0] = v[i - 1][0] && (s1[i -1] == s3[i - 1]);
        for (int i = 1; i <= s2.size(); i ++)
            v[0][i] = v[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        for (int i = 1; i <= s1.size(); i ++)
            for (int j = 1;j <= s2.size(); j ++) {
                v[i][j] = (v[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (v[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        return v[s1.size()][s2.size()];
    }
};
