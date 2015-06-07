/*
 * don't need to sort, just begin from the num given.
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {

        vector<vector<int> > ret;
        ret.push_back(num);

        vector<int> origin = num;

        if (num.size() == 0 || num.size() == 1)
            return ret;

        int i = num.size() - 1;
        for (;;) {
            int ii = i;
            -- i;
            if (num[i] < num[ii]) {
                int j = num.size() - 1;
                while (num[i] >= num[j])
                    j --;
                num[i] ^= num[j];
                num[j] ^= num[i];
                num[i] ^= num[j];

            reverse(num.begin() + ii, num.end());
            if (num == origin)
                return ret;
            else {
                ret.push_back(num);
                i = num.size() - 1;
            }

            }

            if (i == 0) {
                reverse(num.begin(), num.end());
                if (num == origin)
                    return ret;
                else {
                    ret.push_back(num);
                    i = num.size() - 1;
                }
            }
                
        }
        
    }
};
