class Solution {
public:
    bool isAD(char ch) {
        return isdigit(ch) || isalpha(ch);
    }
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return true;
        int left = -1;
        int right = s.size();
        while (left < right) {
            left ++;
            right --;
            if (left > right)
                break;
            while (left < s.size() && !isAD(s[left]))
                left ++;
            while (right >= 0 && !isAD(s[right]))
                right --;
            if (left < right) {
                if (s[left] == s[right])
                    continue;
                int dis = 'a' - 'A';
                if ( (s[left] >= 'a' && s[left] - dis == s[right])
                      || (s[right] >= 'a' && s[right] - dis == s[left]))
                     continue;

                return false;
            }
        }
        return true;
    }
};