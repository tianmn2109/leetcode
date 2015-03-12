/*
 *   1: when x = 1.0 return 1.
 *   2: when x = -1.0, return 1.0 or -1.0 decided by n, if n % 2 == 0, return 1.0, otherwise, return -1.0;
 *   3: when x = 0, return 0;
 *   4: when x = 1, return 1;
 *   5: when n == 0, retun 1.0;
 *   6: when n == 1, return x;
 *   7: Setting the min value to avoid exceeding time, when the middle value is less than min, we can make the result is ret, and return.
 */
class Solution {
public:
    double pow(double x, int n) {

        if (n == 0)
            return 1;

        if (n == 1)
            return x;

        bool flag = false;

        if (x < 0) {
            x = -x;
            flag = true;
        }

        if (x == 0)
            return 0;

        if (x == 1) {
            if (flag && (n % 2 != 0))
                return -1.0;
            return 1.0;
        }

        int m = abs(n);
        double ret = 1.0;
        double min = 0.0000000001;

        while (m -- && ret > min) {
            ret *= x;
        }

        if (flag && n % 2)
            ret = -ret;

        if (n < 0)
            return 1.0 / ret;

        return ret;
    }
};
