class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i ++) {
            int temp = s[i] - 'A' + 1;
            ret = ret * 26 + temp;
        }
        return ret;
    }
};
