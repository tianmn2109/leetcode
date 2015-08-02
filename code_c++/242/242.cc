class Solution {
public:
    bool isAnagram(string s, string t) {
        char m[256];
        memset(m, 0, 256);
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i ++)
            m[s[i]] ++;
        for (int i = 0; i < t.size(); i ++) {
            m[t[i]] --;
        }
        for (int i = 0; i < 256; i ++)
            if (m[i] != 0)
                return false;
        return true;
    }
};
