class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        string temp;
        for (int i = (int)s.size() - 1; i >= 0; i --) {
            if (s[i] == ')' || s[i] == '+' || s[i] == '-')
                s2.push(s[i]);
            else if (isdigit(s[i])) {
                temp = s[i] + temp;
                if (i == 0 || s[i - 1] > '9' || s[i - 1] < '0') {
                    s1.push(stoi(temp));
                    temp = "";
                }
            }
            else if (s[i] == '('){
                while (s2.top() != ')')
                    cal(s1, s2);
                s2.pop();
            }
        } 
        while (!s2.empty())
            cal(s1, s2);
        return s1.top();
    }
    void cal(stack<int> &s1, stack<char> &s2) {
        int op1 = s1.top();
        s1.pop();
        int op2 = s1.top();
        s1.pop();
        char op = s2.top();
        s2.pop();
        if (op == '+')
            s1.push(op1 + op2);
        if (op == '-')
            s1.push(op1 - op2);
    }
};
