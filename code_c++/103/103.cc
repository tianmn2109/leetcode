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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int cur = 0;
        int last = 1;
        int next = 1;
        int level = 0;
        queue<TreeNode *> q;
        stack<TreeNode *> stk;
        vector<vector<int> > ret;
        vector<int> v;
        if (root != NULL)
            q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            v.push_back(temp->val);
            cur ++;
            if (level % 2 == 0) {
                if (temp->left != NULL) {
                    stk.push(temp->left);
                    next ++;
                }
                if (temp->right != NULL) {
                    stk.push(temp->right);
                    next ++;
                }
            }
            else {
                if (temp->right != NULL) {
                    stk.push(temp->right);
                    next ++;
                }
                if (temp->left != NULL) {
                    stk.push(temp->left);
                    next ++;
                }
            }
            if (cur == last) {
                last = next;
                level ++;
                ret.push_back(v);
                v.clear();
               
                while (!stk.empty()) {
                    TreeNode *p = stk.top();
                    stk.pop();
                    q.push(p);
                }
            }
        }
        return ret;
    }
};
