class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > p(s.size(), vector<bool>(s.size(), false));

        vector<int> v(s.size() + 1);
        for (int i = 0; i <= s.size(); i ++)
            v[i] = s.size() - i;
        for (int i = s.size() - 1; i >= 0; i --) {
            for (int j = i; j < s.size(); j ++) {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                    v[i] = min(v[i], v[j + 1] + 1);
                }
            }
        }
     return v[0] - 1;
    }
};