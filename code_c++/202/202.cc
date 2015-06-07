/**
 *  Using a set to store the numbers product in the process.
 *  if the number already appears in the set, then it will for a circle, and will never ends.
 */
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 0) {
            if (n == 1)
                return true;
            s.insert(n);
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            if (s.count(sum))
                break;
            n = sum;
        }
        return false;
    }
};
