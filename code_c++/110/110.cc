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
    int depthOfTree(TreeNode *root) {
        if (root == NULL)
            return 0;
        else {
            return 1 + max(depthOfTree(root->left), depthOfTree(root->right));
        }
    }
    bool transOrder(TreeNode *root) {
        if (root == NULL)
            return true;
        if (!transOrder(root->left) || !transOrder(root->right))
            return false;
        int leftHeight = depthOfTree(root->left);
        int rightHeight = depthOfTree(root->right);
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        return transOrder(root);
    }
};
