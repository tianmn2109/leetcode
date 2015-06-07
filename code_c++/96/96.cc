class Solution {
public:
    int numTrees(int n) {
        int *a = new int[n + 1];
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;
        a[3] = 5;
        for (int i = 4; i <= n; i ++) {
            int temp = 0;
            for (int k = 0; k < i; k ++) 
                temp += a[k] * a[i - k - 1];
            a[i] = temp;
        }
        return a[n];
    }
};
