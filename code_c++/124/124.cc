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
    int maxLen;
    int pathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        int leftSum = pathSum(root->left);
        int rightSum = pathSum(root->right);
        int val = root->val;
        if (leftSum > 0)
            val += leftSum;
        if (rightSum > 0)
            val += rightSum;
        maxLen = max(maxLen, val);
        return max(root->val, max(root->val + leftSum, root->val + rightSum));
    }
    int maxPathSum(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        maxLen = root->val;
        pathSum(root);
        return maxLen;
    }
};