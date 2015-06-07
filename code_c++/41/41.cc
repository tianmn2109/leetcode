/*
 * 
 */
class Solution {
public:

    int firstMissingPositive(int A[], int n) {

        int i = 0;
        while (i < n) {
            if (A[i] >0 && A[i] <= n && A[i] != A[A[i] - 1]) {  // if the value in the final position is not equal to A[i], swap values in those two position.
                int temp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = temp;
            }
            else
                i ++;
        }
        for (int i = 0; i < n; i ++) {
            if (i + 1 != A[i])
                return i + 1;
        }
        return i + 1;
    }
};
