class Solution {
public:
    vector<vector<string> > ret;
    void gen(vector<string> v, vector<vector<bool> > &dp, string &s, int left, int right) {
        if (left > right) {
            ret.push_back(v);
            return ;
        }
        for (int i = left; i <= right; i ++) {
            if (dp[left][i] == true) {
                v.push_back(s.substr(left, i - left + 1));
                gen(v, dp, s, i + 1, right);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i ++)
            dp[i][i] = true;
        for (int len = 2; len <= s.size(); len ++)
            for (int i = 0; i < s.size() - len + 1; i ++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (dp[i + 1][j - 1] == true || j - i < 2))
                    dp[i][j] = true;
            }
        vector<string> v;
        gen(v, dp, s, 0, s.size() - 1);
        return ret;
    }
};
