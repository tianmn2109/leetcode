class Solution {
public:
    void reverse(int num[], int left, int right) {
        while (left < right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
            left ++;
            right --;
        }
    }
    void rotate(int nums[], int n, int k) {
        k = k % n;
        k = n - k;

        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, n - 1);
    }
};
