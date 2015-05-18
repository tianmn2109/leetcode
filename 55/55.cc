class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        int last = nums[0];
        int i = 0;
        while (i <= last && i < nums.size()) {
            if (i + nums[i] > last)
                last = i + nums[i];
            if (last >= nums.size() - 1)
                break;
            i ++;
        }
        if (last >=nums.size() - 1)
            return true;
        return false;
    }
};
