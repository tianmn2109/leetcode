class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        map<string, int> m;

        for (int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) == m.end()) {
                m[s] = i;
            }
            else {
                if (m[s] >= 0) {
                    ret.push_back(strs[m[s]]);
                    m[s] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};
