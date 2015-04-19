class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> v(s.size() + 1, false);
        v[0] = true;
        for (int i = 1; i <s.size() + 1; i ++) {
            for (int j = i - 1; j >= 0; j --) {
                if (v[j] == true && wordDict.count(s.substr(j, i - j))) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v[s.size()];
    } 
};
