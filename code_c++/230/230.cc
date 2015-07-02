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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (p != NULL) {
            stk.push(p);
            p = p->left;
        }
        int num = 0;
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            num ++;
            if (num == k)
                return cur->val;
            cur = cur->right;
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
        }
    }
};
