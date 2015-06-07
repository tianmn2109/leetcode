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
    int d(TreeNode *root) {
        if (root == NULL)
            return 0;
        return max(d(root->left), d(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return d(root);
    }
};
