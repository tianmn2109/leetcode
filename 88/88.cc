/*
 *  compare from the end to the start.
 */
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
       int i = m + n - 1;
       m --;
       n --;
       while (m >=0 && n >= 0) {
           if (A[m] < B[n]) 
               A[i --] = B[n --];
           else 
               A[i --] = A[m --];
       } 
       while (n >= 0)
           A[i --] = B[n --];
    }
};
