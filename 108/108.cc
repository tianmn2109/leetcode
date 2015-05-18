/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *convertToTree(vector<int> &nums, int left, int right) {
        if (left > right)
            return NULL;
        int middle = (left + right) / 2;
        TreeNode *ret = new TreeNode(nums[middle]);
        ret->left = convertToTree(nums, left, middle - 1);
        ret->right = convertToTree(nums, middle + 1, right);
        return ret;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertToTree(nums, 0, nums.size() - 1);
    }
};
