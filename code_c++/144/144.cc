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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ret;
        TreeNode *p = NULL;
        if (root != NULL)
            stk.push(root);
        
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            while (p != NULL) {
                if (p->right != NULL)
                    stk.push(p->right);
                ret.push_back(p->val);
                p = p->left;
            }
        }
        return ret;
    }
};