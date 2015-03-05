/*
 * overflow: abs(0x80000000) = 0x80000000  abs value is still negative.
 * 0x80000000 / -1 = overflow . Value is still ox80000000. return max positive integer 0x7fffffff.
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag =true;
        if ( (dividend>0 && divisor>0) || (dividend<0 && divisor<0) )
            flag = false;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long c = 0;
        long long count = 0;
        long long ret = 0;
        while (a >= b) {
            c = b;
            a = a - b;
            count = 1;
            ret += count;
            while (a - c - c >= 0) {
                count += count;
                ret += count;
                a = a - c - c;
                c += c;
            }
        }
        if (!flag && ret > 0x7fffffff)
            return 0x7fffffff;

        return  flag ? -ret : ret;
    }
};
