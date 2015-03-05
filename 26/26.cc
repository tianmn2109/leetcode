class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0 || n == 1)
            return n;

        int k = 0;
        for (int i = 1; i < n; i ++) {
            if (A[i] == A[k])
                continue;
            A[++k] = A[i];
        }
        return k + 1;
    }
};
