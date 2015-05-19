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
    void DFS(TreeNode *root, int &sum, int curSum) {
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL) {
            curSum = curSum * 10 + root->val;
            sum += curSum;
            return ;
        }
        curSum = curSum * 10 + root->val;
        DFS(root->left, sum, curSum);
        DFS(root->right, sum, curSum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curSum = 0;
        DFS(root, sum, curSum);
        return sum;
    }
};
