// 1
class Solution {
public:
    int calculate(string s) {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int sign = 1;
        int num = 0;
        int ans = 0;

        // always transform s into ( s )
        signs.push(1);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (num) {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
    }
};


// 2
Thanks for sharing! A little shorter one.

class Solution {
public:
    int calculate(string s) {
        stack<int> calcst;
        calcst.push(1);
        s += ')';
        int sign = 1, num = 0, i = 0, ans = 0;
        for (i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
            }else if (s[i] == '+' || s[i] == '-' || s[i] == ')'){
                ans += calcst.top() * sign * num;
                if (s[i] == ')') calcst.pop();
                sign = s[i] == '-' ? -1 : 1;
                num = 0;
            }else if (s[i] == '('){
                calcst.push(calcst.top() * sign);
                sign = 1;
            }
        }
        return ans;
    }
};


// 3
A plus sign can be ignored since it has no effect. A minus sign negates the signs contained within a pair of parentheses.

A ')' matches the nearest '(', so we can use a stack structure to keep track of the negation context. When we encounter '(', save the current context and negate it. When ')', restore the previous context.

#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        typedef long long ll;
        vector<int> ctx;
        int contextNumberMult = 1;
        int localNumberMult = 1;
        int ans=0;
        for (const char *x = s.c_str();*x;x++){
            switch(*x){
            case '-':
                localNumberMult = -1;
                break;
            case '(':
                contextNumberMult *= localNumberMult;
                ctx.push_back(localNumberMult);
                localNumberMult = 1;
                break;
            case ')':
                contextNumberMult *= ctx.back();
                ctx.pop_back();
            case ' ':
            case '+':
                break;
            default:{
                char *end;
                ll n=strtol(x,&end,10);
                ans += n * contextNumberMult  * localNumberMult ;
                localNumberMult = 1;
                x = end-1;
            }}
        }
        return ans;
    }
};
