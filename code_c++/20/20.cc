#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if (s.size() == 0)
            return true;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else {
                if ( (!stk.empty()) && 
                     ( (s[i] == ')' && stk.top() == '(') || (s[i] == ']' && stk.top() == '[') 
                       || (s[i] == '}' && stk.top() == '{') ) ) 
                {
                    stk.pop();     
                }
                else 
                {
                    return false;
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
