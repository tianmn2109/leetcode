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
public:;
    int countNodes(TreeNode* root) {
        return binaryGet(root, 0);
    }
    int getLeftHeight(TreeNode * node) {
        int h = 0;
        while (node != NULL) {
            node = node->left;
            h ++;
        }
        return h;
    }
    int getRightHeight(TreeNode * node) {
        int h = 0;
        while (node != NULL) {
            node = node->right;
            h ++;
        }
        return h;
    }
    int binaryGet(TreeNode * node, int curSum) {
        int left = getLeftHeight(node);
        int right = getRightHeight(node);
        if (left == right)
            return curSum + pow(2, left) - 1;
        if (getRightHeight(node->left) + 1 == left)
            return binaryGet(node->right, curSum + pow(2, left - 1));
        else
            return binaryGet(node->left, curSum + pow(2, right - 1));
    }
};
