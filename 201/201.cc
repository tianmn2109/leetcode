class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m && m != n) {
            m >>= 1;
            n >>= 1;
            count ++;
        }
        return m << count;
    }
};
