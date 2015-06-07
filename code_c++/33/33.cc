/*
 * Asumming that A[left...right]. middle = (left + middle) / 2.
 * The two sections accordenced with the condition that, A[middle] >= A[left] && A[middle] > A[right], when the middle element in the first section
 * and A[middle] <= A[right] && A[middle] < A[left] when the middle element in the second section.
 * in other conditions, it has not been rotated.
 */
class Solution {
public:
    int binarysearch(int A[], int left, int right, int target) { // binary search
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] == target)
                return middle;
            if (A[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }

    int searchR(int A[], int left, int right, int target) {
        int middle = (left + right) / 2;
        int ret = 0;
        if (A[middle] == target)
            return middle;

        if (A[middle] >= A[left] && A[middle] > A[right]) {
            if ((ret = binarysearch(A, left, middle - 1, target)) != -1)
                return ret;
            return searchR(A, middle + 1, right, target);
        }
        else if (A[middle] < A[left] && A[middle] <=  A[right]) {
                if ((ret = binarysearch(A, middle + 1 , right, target)) != -1)
                    return ret;
                return searchR(A, left, middle - 1, target);
        }
        else {
            return binarysearch(A, left, right, target);
        }
    }
    int search(int A[], int n, int target) {
        searchR(A, 0, n - 1, target);
    }
};
