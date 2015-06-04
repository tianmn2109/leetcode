class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        bool flagPoint = false;
        bool hasDigit = false;
        bool hasExp = false;
        int len = s.size();
        i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')            // ingore the last white space 
            i --;
        if (i < 0)
            return false;
        len = i + 1;
        i = 0;
        while (i < s.size() && s[i] == ' ')   // ingore white space in the front
            i ++;
        if (i == s.size())                      // return false if the string only has white space
            return false;
        if (s[i] == '+' || s[i] == '-')        // step forward if the num has positive or negative symbol
            i ++;
        while (i < len) {
            if (s[i] == 'e' || s[i] == '.' || isdigit(s[i])) {           // the exp number must be a interger
                if (s[i] == '.') {
                    if (flagPoint)
                        return false;
                    flagPoint = true;
                }
                else if (s[i] == 'e') {
                    if (!hasDigit)
                        return false;
                    if (hasExp)
                        return false;
                    hasExp = true;
                    flagPoint = true;
                    if (i + 1 == len)
                        return false;
                    if (s[i + 1] == '+' || s[i + 1] == '-')
                        i ++;
                    if (i + 1 == len)
                        return false;
                }
                else {
                    hasDigit = true;
                }
            }
            else
                return false;
            i ++;
        }
        if (!hasDigit)
            return false;
        return true;
    }
};
