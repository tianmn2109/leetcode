class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int> > v(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i ++)
            if (wordDict.count(s.substr(i, 1)))
                v[i][i] = 1;
        for (int r = 2; r <= s.size(); r ++)
            for (int i = 0; i <= s.size() - r; i ++) {
                if (wordDict.count(s.substr(i, r))) {
                    v[i][i + r - 1] = 1;
                    continue;
                }
                for (int j = i; j < i + r - 1; j ++) {
                    if (v[i][j] == 1 && v[j + 1][i + r - 1] == 1) {
                        v[i][i + r - 1] = 1;
                        break;
                    }
                }
            }
        return v[0][s.size() - 1] == 1 ? true : false;
    } 
};
