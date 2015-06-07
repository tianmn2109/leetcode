class Solution {

public:

    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)

            return 0;

        unordered_map<int, int> um;

        int maxLen = 1;

        for (int i = 0; i < nums.size(); i ++) {

            if (um.find(nums[i] - 1) != um.end())

                um[nums[i]] = um[nums[i] - 1] + 1;

            else {

                um[nums[i]] = 1;

            }

            int k = nums[i] + 1;

            while (um.find(k) != um.end()) {

                um[k] += um[nums[i]];

                k ++;

            }

            maxLen = max(maxLen, um[k - 1]);

        }

        return maxLen;

    }

};
