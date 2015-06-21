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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ret;
        TreeNode *p = NULL;
        p = root;
        while (p != NULL) {
            stk.push(p);
            p = p->left;
        }
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            ret.push_back(p->val);
            p = p->right;
            while (p != NULL) {
                stk.push(p);
                p = p->left;
            }
        }
        return ret;
    }
};
