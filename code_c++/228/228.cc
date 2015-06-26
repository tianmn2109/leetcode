class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string range = "";
        vector<string> ret;
        if (nums.size() == 0)
            return ret;
        range = to_string(nums[0]);
        int count = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (i > 0 && nums[i] != nums[i - 1] + 1) {
                if (count > 1) {
                    range += "->";
                    range += to_string(nums[i - 1]);
                }
                ret.push_back(range);
                range = to_string(nums[i]);
                count = 0;
            }
            count ++;
        }
        if (count > 1) {
            range += "->";
            range += to_string(nums[nums.size() - 1]);
        }
        ret.push_back(range);
        return ret;
    }
};
