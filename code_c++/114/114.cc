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
    void flatten(TreeNode* root) {
        stack<TreeNode *> stk;
        if (root != NULL)
            stk.push(root);
        TreeNode *prev = NULL;
        while (!stk.empty()) {
            TreeNode *p = stk.top();
            stk.pop();
            while (p != NULL) {
                if (p->right != NULL)
                    stk.push(p->right);
                if (prev != NULL) {
                    prev->left = NULL;
                    prev->right = p;
                }
                prev = p;
                p = p->left;
            }
        }
    }
};