class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int minLen = 0x7FFFFFFF;
        int left = 0;
        int right = 0;
        int tempSum = nums[0];
        while (1) {
            while (right < nums.size() - 1 && tempSum < s)
                tempSum += nums[++ right];
            if (right == nums.size() - 1 && tempSum < s)
                break;
            while (tempSum >= s)
                tempSum -= nums[left ++];
            minLen = min(minLen, right - left + 2);
        }
        return minLen == 0x7FFFFFFF ? 0 : minLen;
    }
};
