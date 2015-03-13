class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() == 0)
            return ret;

        sort(num.begin(), num.end());
        ret.push_back(num);
        int i = num.size() - 1;
        for(; ;) {
            int ii = i;
            i --;
            if ( i >= 0 && num[i] < num[ii]) {
                int j = num.size() - 1;
                while (num[j] <= num[i])
                    j --;
                num[i] ^= num[j];
                num[j] ^= num[i];
                num[i] ^= num[j];
                reverse(num.begin() + ii, num.end());
                ret.push_back(num);
                i = num.size() - 1;
                continue;
            }
            if (i < 0)
                break;
        }
        return ret;
    }
};
