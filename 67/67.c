/*
 * reverse the two num, add ,then  reverse the result
 */
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0)
            return b;

        if (b.size() == 0)
            return a;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string str = "";
        int over = 0;
        int i = 0;

        for (i = 0;i < min(a.size(), b.size()); i ++) {
            int temp = a[i] - '0' + b[i] - '0' + over;
            char ch = temp % 2 + '0';
            over = temp / 2;
            str += ch;
        }

        string c = (a.size() < b.size()) ? b : a;
        for (; i < c.size(); i ++) {
            int temp = c[i] - '0' + over;
            char ch = temp % 2 + '0';
            over = temp / 2;
            str += ch;
        }

        if (over) {
            str += "1";
        }

        reverse(str.begin(), str.end());
        return str;
    }
};
