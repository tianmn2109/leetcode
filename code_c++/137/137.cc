class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0;   // represent the apperance one time of 1
        int two = 0;   // represent the apperance one time of 2
        int three = 0; // represent the apperance one time of 3

        for (int i = 0; i < n; i ++) {
            two |= A[i] & one;         // calculate the apperance two time's 1
            one = A[i] ^ one;          // if 1 time 1, 2 times 0, 3 times 1
            three = ~(one & two);      // the bit 1 represent the 3 times of 1, then flip it
            one &= three;             // if 1 apperes 3 times , clear it
            two &= three;
        }
        return one;
    }
};
