class Solution {
public:
    int roblinear(int *ary, int n) {
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int c = max(a, b);
            a = b + ary[i];
            b = c;
        }
        return max(a, b);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int a = roblinear(&nums[2], n - 3) + nums[0];
        int b = roblinear(&nums[1], n - 1);
        return max(a, b);
    }
};