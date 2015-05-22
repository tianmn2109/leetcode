class Solution {
public:
    string shortestPalindrome(string s) {
        int maxLen = 0;
        string ss = s;
        reverse(ss.begin(), ss.end());
        for (int i = 1; i <= s.size(); i ++) {
            if (s.substr(0, i) == ss.substr(ss.size() - i))
                maxLen = i;
        }
        string strTemp = s.substr(maxLen);
        reverse(strTemp.begin(), strTemp.end());
        return strTemp + s;
    }
};
