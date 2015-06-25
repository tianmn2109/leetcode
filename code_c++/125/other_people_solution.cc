class Solution {
public:
    bool isPalindrome(string s) {
        auto first = s.begin(), last = s.end();
        while (first < last) {
            while (first < last && !isalnum(*first)) { first++; }
            while (first < last && !isalnum(*last)) { last--; }
            if (tolower(*first++) != tolower(*last--)) { return false; }
        }
        return true;
    }
};
