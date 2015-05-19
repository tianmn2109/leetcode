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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> v;
        vector<vector<int> > ret;
        if (root != NULL)
            q.push(root);
        int cur = 0;
        int last = 1;
        int next = 1;
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left != NULL) {
                q.push(temp->left);
                next ++;
            }
            if (temp->right != NULL) {
                q.push(temp->right);
                next ++;
            }
            cur ++;
            if (cur == last) {
                last = next;
                ret.push_back(v);
                v.clear();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
