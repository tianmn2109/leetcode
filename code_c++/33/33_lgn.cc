class Solution {
public:
    int searchRotate(int A[], int left, int right, int target) {
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] == target)
                return middle;
            if (A[middle] >= A[left]) {
                if (A[left] <= target && target < A[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else {
                if (A[middle] < target && target <= A[right])
                    left = middle + 1;
                else 
                    right = middle - 1;
            }
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        return searchRotate(A, 0, n - 1, target);
    }
};