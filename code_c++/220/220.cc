class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> mset;
        for (int i = 0; i < nums.size(); i ++) {
            if (mset.size() == k + 1)
                mset.erase(nums[i - k - 1]);
            auto it = mset.lower_bound(nums[i] - t);
            if (it != mset.end()) {
                int diff = abs(nums[i] - *it);
                if (diff <= t)
                    return true;
            }
            mset.insert(nums[i]);
        }
        return false;
    }
};
