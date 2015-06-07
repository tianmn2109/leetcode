/* method:
 * 1: from the end to the start, find two position accordance with that *i < **i, if there is no such position, then reverse elements between start ang end.
 * 2: then from the end to the start find position j , *j > * i
 * 3: swap *i and *j
 * 4: reverse elements between ii and the end
 */
class Solution {
public:

    void nextPermutation(vector<int> &num) {
        if (num.size() == 0 || num.size() == 1)
            return ;

        int i = num.size() - 1;

        for (;;) {
            int ii = i;
            -- i;

            if (num[i] < num[ii]) {
                int j = num.size() - 1;
                while (num[i] >= num[j])
                    j --;

                swap(num[i],num[j]);
                reverse(num.begin() + ii, num.end());
                return ;
            }

            if (i == 0)
            {
                reverse(num.begin(), num.end());
                return ;
            }
        }
    }
};
