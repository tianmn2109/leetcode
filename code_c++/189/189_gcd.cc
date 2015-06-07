class Solution {
public:
    int gcd(int m, int n) {
        while (m % n) {
            int r = m % n;
            m = n;
            n = r;
        }
        return n;
    }

    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k == 0)
            return ;
        k = n - k;
        int d = gcd(n, k);

        for (int i = 0; i < d; i ++) {
            int temp = nums[i];
            int prev = i;
            for (int j = (i + k) % n; j != i; j = (j + k) % n) {
                nums[prev] = nums[j];
                prev = j;
            }
            nums[prev] = temp;
        }
    }
};
