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
    TreeNode *buildTreeAux(vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight)
            return NULL;
        TreeNode *node = new TreeNode(preorder[preLeft]);
        int i = 0;
        for (i = inLeft; i <= inRight; i ++)
            if (inorder[i] == preorder[preLeft])
                break;
        int leftNum = i - inLeft;
        int rightNum = inRight - i;
        node->left = buildTreeAux(preorder, preLeft + 1, preLeft + leftNum, inorder, inLeft, i - 1);
        node->right = buildTreeAux(preorder, preLeft + leftNum + 1, preRight, inorder, i + 1, inRight);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeAux(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
