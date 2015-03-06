/*
 * 
 */
class Solution {
public:
    int searchInsert(int A[], int n, int target) {

        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] == target) 
                return middle;

            if (A[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return left; // this is important. if A[middle] < target, then the insert position should be the middle + 1(left after updated),
                    // however, if A[middle] > target, then the insert position should be the current position(left).
    }
};
