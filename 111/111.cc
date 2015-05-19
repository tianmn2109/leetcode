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
    void DFS(TreeNode *root, int curDep, int &minDep) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL) {
            minDep = min(minDep, curDep + 1);
            return ;
        }
        DFS(root->left, curDep + 1, minDep);
        DFS(root->right, curDep + 1, minDep);
    }
    int minDepth(TreeNode* root) {
        int minDep = 0x7fffffff;
        int curDep = 0;
        DFS(root, curDep, minDep);
        if (minDep == 0x7fffffff)
            return 0;
        return minDep;
    }
};
