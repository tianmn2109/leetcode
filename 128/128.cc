class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int maxLen = 1;
        unordered_set<int> m(nums.begin(), nums.end());
        while (!m.empty()) {
            unordered_set<int>::iterator it = m.begin();
            int high = *it;
            int low = *it;
            m.erase(it);
            while ( (it = m.find(++ high)) != m.end())  
                m.erase(it);
            while ( (it = m.find(-- low)) != m.end() )
                m.erase(it);
            maxLen = max(maxLen, high - low - 1);
        }
        return maxLen;
    }
};
