class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string str = "1";
        while (-- n) {
            int i = 0;
            int count = 0;
            string s = "";
            while (i < str.size()) {
                int j = i + 1;
                count = 1;
                while (j < str.size() && str[i] == str[j]) {
                    count ++;
                    j ++;
                }
                char ch = '0' + count;
                s += ch;
                s += str[i];
                i = j;
            }
            str = s;
        }
        return str;
    }
};
