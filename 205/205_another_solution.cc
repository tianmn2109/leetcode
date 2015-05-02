class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> se;
        for (int i = 0; i < s.size(); i ++) {
            if (m.count(s[i])) {                      //m ｓ到　ｔ　的映射
                if (m[s[i]] != t[i])
                    return false;
            }
            else {
                if (se.count(t[i]))                 //　ｓｅ　　是否ｔ被映射过
                    return false;
                else {
                    m[s[i]] = t[i];
                    se.insert(t[i]);
                }
            }
        }
        return true;
    }
};
