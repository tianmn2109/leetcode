class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (k > nums.size() || k < 1)
            return ret;
        deque<pair<int, int> > q;
        for (int i = 0; i < k - 1; i ++) {
            while (!q.empty() && q.back().first < nums[i]) {
                q.pop_back();
            }
            q.push_back(pair<int, int>(nums[i], i));
        }
        for (int i = k - 1; i < nums.size(); i ++) {
            while (!q.empty() && i - q.front().second + 1 > k)
                q.pop_front();
            while (!q.empty() && q.back().first < nums[i]) {
                q.pop_back();
            }
            q.push_back(pair<int, int>(nums[i], i));
            ret.push_back(q.front().first);
        }
        return ret;
    }
};
