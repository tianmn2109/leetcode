/*   reference for the answer in the internet.
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> v(s.size(),false);

        stack<int> stk;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')' && (!stk.empty()) ) {
                v[i] = true;
                v[stk.top()] = true;
                stk.pop();
            }
        }
        int maxvalid = 0;
        int cur = 0;
        for (int i = 0 ; i < v.size(); i ++) {
            if (v[i] == true)
                cur ++;
            else {
                if (cur > maxvalid) {
                    maxvalid = cur;
                }
                 cur = 0;
            }
        }
        if (cur > maxvalid) {
                    maxvalid = cur;
        }
        return maxvalid;
    }
};
