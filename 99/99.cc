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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *prev = NULL;
        TreeNode *cur = root;
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->left;
        }
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (prev != NULL && prev->val > cur->val) {
                if (first == NULL)
                    first = prev;
                second = cur;
            }
            prev = cur;
            cur = cur->right;
            while (cur != NULL) {
                stk.push(cur);
                cur = cur->left;
            }
        }
        swap(first->val, second->val);
    }
};
