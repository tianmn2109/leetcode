class Solution {
public:
    int searchRotate(int A[], int left, int right, int target) {
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (A[middle] == target)
                return middle;
            
            if (A[middle] > A[left]) {
                if (A[left] <= target && target < A[middle])
                    right = middle - 1;
                else 
                    left = middle + 1;
            }
            else if (A[middle] < A[right]) {
                if (A[middle] < target && target <= A[right])
                    left = middle + 1;
                else 
                    right = middle - 1;
            }
            else if (A[left] == A[middle])
                left ++;
            else if (A[right] == A[middle])
                right --;
            
        }
        return -1;
    }
    bool search(int A[], int n, int target) {
        int ret = searchRotate(A, 0, n - 1, target);
        return ret != -1;
    }
};
