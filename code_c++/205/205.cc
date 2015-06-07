class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[256];
        memset(map, 0, 256);
        for (int i = 0; i < s.size(); i ++) {
            if (map[t[i]] == 0) {
                map[t[i]] = s[i];
            }
            else if (s[i] != map[t[i]])
                return false;
        }
        memset(map, 0, 256);
        for (int i = 0; i < s.size(); i ++) {
            if (map[s[i]] == 0) {
                map[s[i]] = t[i];
            }
            else if (t[i] != map[s[i]])
                return false;
        }
        return true;
    }
};
