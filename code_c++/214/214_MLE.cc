class Solution {
public:
    string shortestPalindrome(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i ++)
            dp[i][i] = true;
        for (int r = 2; r <= s.size(); r ++)
            {
                for (int i = 0; i < s.size() - r + 1; i ++) {
                    int j = i + r - 1;
                    if (s[i] == s[j] && (dp[i + 1][j - 1] == true || j - i < 2))
                        dp[i][j] = true;
                }
            }
        int maxLen = 0;
        for (int i = 0; i < s.size(); i ++)
            if (dp[0][i] == true)
                maxLen = i + 1;
        string strTemp = s.substr(maxLen);
        reverse(strTemp.begin(), strTemp.end());
        return strTemp + s;
    }
};
