class Solution {
public:
    int findMin(vector<int>& A) {
        if (A.size() == 0)
            return A[0];
        int left = 0;
        int right = A.size() - 1;
        while (left < right - 1) {
            if (A[left] < A[right])
                return A[left];
            int middle = (left + right) / 2;
            if (A[middle] >= A[left] && A[middle] > A[right])
                left = middle + 1;
            else if (A[middle] <= A[right] && A[middle] < A[left])
                right = middle;
        }
        return A[left] < A[right] ? A[left] : A[right];
    }
};
