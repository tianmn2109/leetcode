// 1
 class Solution {
    public:
        // start is 0 or 1
        int work(vector<int> &nums, int start) {
            int n = nums.size();
            if (n < start + 1) return 0;
            if (n == start + 1) return nums[start];
            if (n == start + 2) return max(nums[start], nums[start+1]);
            if (start == 0)
                --n;
            vector<int> dp(n, 0);
            dp[start] = nums[start];
            dp[start+1] = max(nums[start], nums[start+1]);
            for (int i = start+2; i < n; i++) 
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            return dp.back();
        }

        int rob(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            return max(work(nums, 0), work(nums, 1));
        }
    };


