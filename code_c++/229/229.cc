class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = 0;
        int second = 0;
        int countFirst = 0;
        int countSecond = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (countFirst && nums[i] == first) {
                countFirst ++;
            }
            else if (countSecond && nums[i] == second) {
                countSecond ++;
            }
            else if (countFirst == 0) {
                first = nums[i];
                countFirst = 1;
            }
            else if (countSecond == 0) {
                second = nums[i];
                countSecond = 1;
            }
            else {
                countFirst --;
                countSecond --;
            }
        }
        countFirst = 0;
        countSecond = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == first)
                countFirst ++;
            else if (nums[i] == second)
                countSecond ++;
        }
        vector<int> ret;
        if (countFirst > nums.size() / 3)
            ret.push_back(first);
        if (countSecond > nums.size() / 3)
            ret.push_back(second);
        return ret;
    }
};
