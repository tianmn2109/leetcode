// 1
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = 0, sum = 0, result = INT_MAX;
        while (right < n) {
            while (right < n && sum < s) {  // expend [left,right] to make sum >= s, notice that right is just at right of index where sum >= s;
                sum += nums[right];
                ++right;
            }
            while (left < right && sum >= s) {   // shrink [left, right] to make  it  as small as possible
                result = min(result, right - left);  // there we don't use right - left + 1, because right is just at right of index where sum >= s;
                sum -= nums[left];
                ++left;
            }

        }

        return result == INT_MAX ? 0 : result;

    }
};

// 2
class Solution {
public:
int minSubArrayLen(int s, vector<int>& nums) {
    int firstPos = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minLength = min(minLength, i - firstPos + 1);
            sum -= nums[firstPos++];
        }
    }

    return minLength == INT_MAX? 0 : minLength;
  }
};
