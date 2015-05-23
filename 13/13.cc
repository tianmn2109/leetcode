class Solution {
public:
    int getValue(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i< s.size() - 1; i ++) {
            if (getValue(s[i]) < getValue(s[i + 1]))
                ret -= getValue(s[i]);
            else
                ret += getValue(s[i]);
        }
        ret += getValue(s[s.size() - 1]);
        return ret;
    }
};
