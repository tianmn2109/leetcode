// 1
class Solution {
public:
string longestCommonPrefix(vector<string> &strs) {
    string s("");
    if (strs.size() == 0) return s;
    if (strs.size() == 1) return strs[0];

    for (int j=0; j < strs[0].size(); ++j) {
        char ch = strs[0][j];
        for (int i=1; i<strs.size(); ++i)                   // the exceed will be '\000'
            if (ch != strs[i][j]) return s;
        s += ch; 
    }

    return s;
}
};

