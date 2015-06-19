class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int k = 0;
        if (n < 3)
            return n;
        k = 1;
        for (int i = 2; i < n; i ++) {
            if (A[i] != A[k] || A[i] != A[k - 1] )
                A[++ k] = A[i];
        }
        return k + 1;
    }
};
