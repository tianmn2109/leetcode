class Solution {
public:
    int robLine(int* nums, int n) {
        vector<int> v(n);
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        v[0] = nums[0];
        v[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i ++) {
                v[i] = max(v[i - 2] + nums[i], v[i - 1]);
        }
        return max(v[n - 1], v[n - 2]);
    }
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (nums.size() == 0)
        return 0;
      if (nums.size() == 1)
        return nums[0];
      if (nums.size() == 2)
        return max(nums[0], nums[1]);
      
      int a = robLine(&nums[1], n - 1);
      int b = robLine(&nums[2], n - 3) + nums[0];
      return max(a, b);
    }
};