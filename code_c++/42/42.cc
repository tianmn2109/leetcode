/*
 * the water capicity at position i is decided by the two higher walls besides the two sides of i,
 * first, find the highest wall.
 * second , calculate water capicity in every position from the start and the end to the highest wall.
 * third, if the value in positon i is small than max in its left or right, then it can contain (max - A[i]) water.
 *        else, it can not contain any water in position i, update the max.
 */
class Solution {
public:
    int trap(int A[], int n) {

        int maxid = 0;
        int water = 0;

        int max = A[0];

        for (int i = 0; i < n; i ++) {
            if (A[i] > max) {
                max = A[i];
                maxid = i;
            }
        }

        max = A[0];
        for (int i = 0; i < maxid; i ++) {
            if (A[i] > max) {
                max = A[i];
            }
            else {
                water += max - A[i];
            }
        }

        max = A[n - 1];

        for (int i = n - 1; i > maxid; i --) {
            if (A[i] > max) {
                max = A[i];
            }
            else {
                water += max - A[i];
            }
        }
        return water;
    }
};
