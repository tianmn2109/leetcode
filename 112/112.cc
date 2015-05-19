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
    void DFS(TreeNode *root, int curSum, int sum, bool &isExits) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL) {
            if (curSum + root->val == sum)
                isExits = true;
            return ;
        }
        DFS(root->left, curSum + root->val, sum, isExits);
        DFS(root->right, curSum + root->val, sum, isExits);
    }
    bool hasPathSum(TreeNode *root, int sum) {
        bool isExits = false;
        int curSum = 0;
        DFS(root, curSum, sum, isExits);
        return isExits;
    }
};
