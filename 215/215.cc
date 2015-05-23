class Solution {
public:
    int KthLargest(vector<int>& nums, int start, int end, int k) {
        int left = start;
        int right = end;
        int temp = nums[left];
        while (left < right) {
            while (left < right && nums[right] < temp)
                right --;
            if (left < right)
                nums[left ++] = nums[right];
            while (left < right && nums[left] > temp)
                left ++;
            if (left < right)
                nums[right --] = nums[left];
        }
        nums[left] = temp;
        int newK = left - start + 1;
        if (newK == k)
            return nums[left];
        else if (newK < k)
            return KthLargest(nums, left + 1, end, k - newK);
        else
            return KthLargest(nums, start, left - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return KthLargest(nums, 0, nums.size() - 1, k);
    }
};
