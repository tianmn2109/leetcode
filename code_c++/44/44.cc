class Solution {
public:
    bool isMatch(string s, string p) {
        int pPos = -1;
        int sPos = -1;
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                i ++;
                j ++;
                continue;
            }
            if (p[j] == '*') {
                pPos = j;
                sPos = i;
                j ++;
                continue;
            }
            if (pPos != -1 && sPos != -1) {
                i = sPos + 1;
                j = pPos + 1;
                sPos ++;
                continue;
            }
            return false;
        }
        while (p[j] == '*')
            j ++;
        return j == p.size();
    }
};
