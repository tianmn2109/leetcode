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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *prev = NULL;
        TreeNode *p = root;
        while (p != NULL) {
            stk.push(p);
            p = p->left;
        }
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            if (prev != NULL && prev->val >= p->val)
                return false;
            prev = p;
            p = p->right;
            while (p != NULL) {
                stk.push(p);
                p = p->left;
            }
        }
        return true;
    }
};