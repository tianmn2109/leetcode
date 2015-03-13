/*
 * shuiti
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> v;
        int over = 1;
        reverse(digits.begin(), digits.end());
        for (int i = 0; i < digits.size(); i ++) {
            int sum = digits[i] + over;
            v.push_back(sum%10);
            over = sum / 10;
        }
        if (over)
            v.push_back(1);
        reverse(v.begin(), v.end());
        return v;
    }
};
