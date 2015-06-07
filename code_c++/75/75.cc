class Solution {
public:
    void sortColors(int A[], int n) {

        int left = 0;
        int right = n;
        int i = 0;
        while (i < right) {
            while (i < right && A[i] == 1)
                i ++;
            if (i == right)
		return ;
            if (A[i] == 0)
                swap(A[left ++], A[i ++]);
            else {
                swap(A[-- right], A[i]);
            }
        }
    }
};

