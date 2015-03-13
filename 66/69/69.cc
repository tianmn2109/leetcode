/*
 * Important: the left must be long type, not int, because left * left may larger than MAX_INT
 *            the temp musat be long long.
 */
class Solution {
public:
    int sqrt(int x) {
        if (x == 0 | x == 1)
            return x;
        long left = 1;
        long right = 65536;
        while (left <= right) {
            long long middle = (left + right) / 2;
            long long temp = middle * middle;
            if (temp == x)
                return middle;
            if (temp > x)
                right = middle - 1;
            else 
                left = middle + 1;
        }
        return (left * left < x) ? left : left - 1;
    }
};
