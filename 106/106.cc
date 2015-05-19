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
    TreeNode *buildTreeAux(vector<int> &inorder, int inLeft, int inRight, vector<int> &postorder, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight)
            return NULL;
        TreeNode *node = new TreeNode(postorder[postRight]);
        int i = 0;
        for (i = inLeft; i <= inRight; i ++)
            if (inorder[i] == postorder[postRight])
                break;
        int leftNum = i - inLeft;
        int rightNum = inRight - i;
        node->left = buildTreeAux(inorder, inLeft, i - 1, postorder, postLeft, postLeft + leftNum - 1);
        node->right = buildTreeAux(inorder, i + 1, inRight, postorder, postLeft + leftNum, postRight - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeAux(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};