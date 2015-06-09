class Solution {
public:
    int calculate(string s) {
        stack<string> s1;
        stack<string> s2;
        vector<string> v = convertToTokens(s);
        convert(v, s1, 0, v.size() - 1);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return cal(s2);
    }
    int cal(stack<string> &stk) {
        int ret = 0;
        while (stk.empty() > 1) {
            int op1 = strToInt(stk.top());
            stk.pop();
            int op2 = strToInt(stk.top());
            stk.pop();
            string op = stk.top();
            stk.pop();
            if (op == "+")
                stk.push(intToStr(op1 + op2));
            else
                stk.push(intToStr(op1 - op2));
        }
        return strToInt(stk.top());
    }
    string intToStr(int num) {
        string s;
        while (num) {
            s = s + (char)(num % 10 + '0');
            num /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int strToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i ++)
            ret = ret * 10 + s[i] - '0';
        return ret;
    }
    void convert(vector<string> &v, stack<string> &stk, int left, int right) {
        int i = left;
        while (i <= right) {
            if (v[i] == "+" || v[i] == "-") {
                if (v[i + 1] == "(" || v[i + 1] == ")") {
                    int count = 1;
                    int j = i;
                    i ++;
                    while (i <= right) {
                        if (v[i] == "(")
                            count ++;
                        if (v[i] == ")")
                            count --;
                        if (count == 0)
                            break;
                        i ++;
                    }
                    convert(v, stk, j + 1, i - 1);
                    i ++;
                }
                else {
                    stk.push(v[i + 1]);
                    stk.push(v[i]);
                    i += 2;
                }
            }
            else {
                stk.push(v[i]);
                i ++;
            }
        }
    }
    vector<string> convertToTokens(string s) {
        int i = 0;
        vector<string> v;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i ++;
                continue;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')') {
                char ch = s[i];
                string temp;
                temp += ch;
                v.push_back(temp);
                i ++;
            }
            else {
                string strTemp = "";
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    strTemp += s[i ++];
                v.push_back(strTemp);
            }
        }
        return v;
    }
};
