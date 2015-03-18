/*
 * consider the n may be 0, that return 0.
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        int i = 1;
        while (i <= n) {
            for (int j = v.size() - 1; j >= 0; j --) {
                v.push_back(pow(2, i - 1) + v[j]);
            }
            i ++;
        }
        return v;
    }
};
