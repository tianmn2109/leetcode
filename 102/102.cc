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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        if (root != NULL)                         // important 
            q.push(root);
        vector<vector<int> > ret;
        vector<int> v;
        int curLevel = 0;
        int nextLevel = 1;
        int postLevel = 1;
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                postLevel ++;
            }
            if (temp->right)
            {
                q.push(temp->right);
                postLevel ++;
            }
            v.push_back(temp->val);
            curLevel ++;
            if (curLevel == nextLevel) {
                ret.push_back(v);
                v.clear();
                nextLevel = postLevel;
            }
        }
        return ret;
    }
};
