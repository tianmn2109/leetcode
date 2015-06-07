class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        int localmax = nums[0];
        int localmin = nums[0];
        int retMax = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int a = max(localmax*nums[i], max(nums[i], localmin*nums[i]));
            int b = min(localmax*nums[i], min(nums[i], localmin*nums[i]));
            localmax = a;
            localmin = b;
            if (localmax > retMax)
                retMax = localmax;
        }
        return retMax;
    }
};
