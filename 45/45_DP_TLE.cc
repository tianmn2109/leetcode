class Solution {
public:
    int jump(vector<int>& nums) {
       int maxINT = 0x7fffffff;
       vector<int> v(nums.size() + 1, maxINT);
       for (int i = nums.size() - 1; i >= 0; i --) {
           if (i + nums[i] >= nums.size() - 1) {
               v[i] = 1;
               continue;
           }
           for (int j = i + 1; j <= nums[i] + i; j ++) {
               v[i] = min(v[i], v[j] + 1);
           }
       }
       return v[0];
    }
};
