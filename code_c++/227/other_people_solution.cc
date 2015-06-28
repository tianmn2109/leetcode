// 1
If you don't like the 44 - op ASCII trick, you can use op == '+' ? 1 : -1 instead. And wow, I didn't know C++ has or. I'm a Python guy and wrote that out of habit and only realized it after getting this accepted :-)

int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}


// 2
O(n) time, O(1) space, one scan C++ solution, code maybe optimized though. Every time I got a number, I will aggregate it into the temp result. when I met '+' or '-", temp result will be aggregated into the final result sum.

 int calculate(string s) {
    int sum = 0; 
    if(s.size() < 1) return sum; 
    int i = 0; 
    int last = 0, last_result = 1;  
    char last_operator = '+'; //remember the last operator
    int sign = 1; 
    while(i < s.size()){
        if(s[i] == ' '){++i; continue;}
        if(s[i] == '+' || s[i] == '-'){
            sum += last_result * sign;
            sign = s[i++] == '+' ? 1 : -1; 
            last_result = 1;
            last_operator = '+'; 
        }
        else if(s[i] == '/' || s[i] == '*'){
            last_operator = s[i];
            ++i; 
        }
        if(isdigit(s[i])){
            last = 0; 
            while(i < s.size() && isdigit(s[i])){
                last =  last * 10 + s[i++] - '0'; 
            }

            if(last_operator == '*') last_result *= last;
            else if(last_operator == '/') last_result /= last;
            else  last_result = last; 
        }
    }
    sum += last_result * sign;
    return sum; 
}


// 3
class Solution {
public:
    int calculate(std::string s) {
        len = s.size();
        int i = 0, sign = 1, num = getNext(s, i), res = 0;
        // s[i] is '+', '-', '*' or '/'
        while (i < len)
            if (s[i] == '+') {
                res += num * sign;
                sign = 1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '-') {
                res += num * sign;
                sign = -1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '*')
                num *= getNext(s, ++i);
            else
                num /= getNext(s, ++i);
        res += num * sign;
        return res;
    }
private:
    int len;
    int getNext(std::string &s, int &i) {
        int next = 0;
        while (i < len) {
            if (s[i] >= '0' && s[i] <= '9')
                next = next * 10 + s[i] - '0';
            else if (s[i] != ' ')
                return next;
            ++i;
        }
        return next;
    }
};
