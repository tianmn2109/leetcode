class Solution {
public:
    int jump(vector<int>& nums) {
       int minStep = 0;
       if (nums.size() == 0 || nums.size() == 1)
           return minStep;
       int last = nums[0];
       int prev = nums[0];
       int i = 0;
       minStep = 1;
       while (i <= last && i < nums.size()) {
           if (i > prev) {
               prev = last;
               minStep ++;
           }
           if  (i + nums[i] > last)
               last = i + nums[i];
           i ++;
       }
       return minStep;
    }
};
