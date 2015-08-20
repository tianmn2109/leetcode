class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 0);
        v[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        int next2 = 2;
        int next3 = 3;
        int next5 = 5;
        for (int i = 1; i < n ;i ++) {
            int cur = min(next2, min(next3, next5));
            v[i] = cur;
            if (next2 == cur) {
                i2 ++;
                next2 = v[i2] * 2;
            }
            if (next3 == cur) {
                i3 ++;
                next3 = v[i3] * 3;
            }
            if (next5 == cur) {
                i5 ++;
                next5 = v[i5] * 5;
            }
        }
        return v[n - 1];
    }
};
