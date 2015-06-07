class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int *a = new int [n];
        int count = 1;
        for (int i = 2; i < n; i ++) {
            if (i % 2 == 0)
                a[i] = 1;
            else
                a[i] = 0;
        }
        int j = 3;
        for (j = 3; j < n; j ++) {
            if (j * j > n)
                break;
            if (a[j] == 0)
            {
                count ++;
                for (int i = 2; i * j < n; i ++)
                    a[i * j] = 1;
            }
        }
        for (; j < n; j ++)
            if (a[j] == 0)
                count ++;
        return count;
    }
};
