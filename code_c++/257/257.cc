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
    void generate(TreeNode* root, string str, vector<string> &ret) {
        if (root == NULL)
            return ;
        str = str + "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(str);
            return ;
        }
        if (root->left != NULL)
            generate(root->left, str, ret);
        if (root->right != NULL)
            generate(root->right, str, ret);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL)
            return ret;
        string str = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(str);
            return ret;
        }
        generate(root->left, str, ret);
        generate(root->right, str, ret);
        return ret;
    }
};
