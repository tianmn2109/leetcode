class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i ++) {
            if (tokens[i] == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = b + a;
                stk.push(c);
            }
            else if (tokens[i] == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = b - a;
                stk.push(c);
            }
            else if (tokens[i] == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = b * a;
                stk.push(c);
            }
            else if (tokens[i] == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = b / a;
                stk.push(c);
            }
            else {
                int c = atoi(tokens[i].c_str());
                stk.push(c);
            }
        }
        int ret = stk.top();
        return ret;
    }
};
