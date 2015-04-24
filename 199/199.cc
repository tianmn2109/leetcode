/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<pair<TreeNode*, int> > q;
        vector<int> v;
        if (root == NULL)
            return v;
        q.push(make_pair(root, 0));
        int dep = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            if ((temp.first)->left != NULL) {
                q.push(make_pair((temp.first)->left, dep + 1));
            }
            if ((temp.first)->right != NULL) {
                q.push(make_pair((temp.first)->right, dep + 1));
            }
            if (!q.empty() && (temp.second != q.front().second)) {
                v.push_back((temp.first)->val);
                dep ++;
            }
            if (q.empty()) {
                v.push_back((temp.first)->val);
            }
        }
        return v;
    }
};
