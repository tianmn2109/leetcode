// 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        int e = nums.size()-1;
        int b = 0;
        while (b<e) {
            int mid = b + (e-b)/2;
            if (nums[mid] > nums[e]) 
                b = mid+1;
            else if (nums[mid] < nums[e])
                e = mid;
        }
        return nums[b];
    }
};

// 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int e = nums.size()-1;
        int b = 0;
        while (b<e) {
            int mid = b + (e-b)/2;
            if (nums[mid] > nums[e]) 
                b = mid+1;
            else if (nums[mid] < nums[e])
                e = mid;
        }
        return nums[b];
    }
};
