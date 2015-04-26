class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        int temp = 0;
        char ch;
        while (n) {
            n --;
            temp = n % 26;
            ch = temp + 'A';
            s += ch;
             n = n / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
