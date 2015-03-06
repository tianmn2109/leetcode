/*
 * the thought of binary search.
 */
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        vector<int> ret;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] == target) {
                int start = middle;
                int end = middle;
                while (start >= left && A[start] == target) //**** important : >= not >
                    start --;
                while (end <= right && A[end] == target )
                    end ++;
                ret.push_back(++start);
                ret.push_back(--end);
                return ret;
            }

            if (A[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};
