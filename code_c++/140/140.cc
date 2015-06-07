class Solution {
public:
    void dfs(string &s, vector<string> &res, string str, int dep, vector<vector<int> > &rec) {
        if (dep <= 0)
            res.push_back(str.substr(0, str.size() - 1));
        else {
            for (int i = 0; i < rec[dep].size(); i ++)
                dfs(s, res, s.substr(rec[dep][i] + 1, dep - rec[dep][i]) + " " + str, rec[dep][i], rec);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        s = "#" + s;
        vector<string> res;
        vector<vector<int> > rec(s.size());
        vector<int> f(s.size(), false);
        f[0] = true;
        for (int i = 1; i < s.size(); i ++)
            for (int j = 0; j < i; j ++) {
                if (f[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
                    f[i] = true;
                    rec[i].push_back(j);
                }
            }
        dfs(s, res, "", s.size() - 1, rec);
        return res;
    }
};