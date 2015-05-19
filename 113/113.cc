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
    void DFS(TreeNode *root, vector<vector<int> > &ret, vector<int> path, int curSum, int sum) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL) {
            if (root->val + curSum == sum) {
                path.push_back(root->val);
                ret.push_back(path);
            }
            return ;
        }
        path.push_back(root->val);
        DFS(root->left, ret, path, curSum + root->val, sum);
        DFS(root->right, ret, path, curSum + root->val, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> path;
        int curSum = 0;
        DFS(root, ret, path, curSum, sum);
        return ret;
    }
};
