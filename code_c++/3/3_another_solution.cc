class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256] = {false};
        int maxLen = 0;
        for (int i = 0, j = 0; j < s.size(); j ++) {
            if (flag[s[j]] == false) {
                flag[s[j]] = true;
                maxLen = max(maxLen, j - i + 1);
                continue;
            }
            else {
                while (s[i] != s[j]) {
                    flag[s[i]] = false;
                    i ++;
                }
                i ++;
            }
        }
        return maxLen;
    }
};
