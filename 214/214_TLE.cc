class Solution {
public:
    bool isPalindrome(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left ++, right --)
            if (s[left] != s[right])
                return false;
            return true;
    }
    string shortestPalindrome(string s) {
        int maxLen = 0;
        for (int i = 1; i <= s.size(); i ++)
            if (isPalindrome(s.substr(0, i)))
                maxLen = max(maxLen, i);
        string strTemp = s.substr(maxLen);
        reverse(strTemp.begin(), strTemp.end());
        return strTemp + s;
    }
};
