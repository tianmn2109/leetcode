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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        vector<int> ret;
        if (root != NULL)
            stk.push(root);
        while (!stk.empty()) {
            cur = stk.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                ((prev != NULL) && (cur->left == prev || cur->right == prev))) {
                    stk.pop();
                    ret.push_back(cur->val);
                    prev = cur;
                }
            else {
                if (cur->right != NULL)
                    stk.push(cur->right);
                if (cur->left != NULL)
                    stk.push(cur->left);
            }
        }
        return ret;
    }
};