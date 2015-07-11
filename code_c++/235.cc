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
    void path(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> v, vector<TreeNode *> &vp, vector<TreeNode *> &vq, int &count) {
        if (root == NULL)
            return ;
        v.push_back(root);
        if (root == p) {
            vp = v;
            count ++;
        }
        if (root == q) {
            vq = v;
            count ++;
        }
        if (count == 2)
            return ;
        path(root->left, p, q, v, vp, vq, count);
        path(root->right, p, q, v, vp, vq, count);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v;
        vector<TreeNode *> vp;
        vector<TreeNode *> vq;
        TreeNode *ret = NULL;
        int count = 0;
        path(root, p, q, v, vp, vq, count);
        for (int i = 0; i < min(vp.size(), vq.size()); i ++) {
            if (vp[i] != vq[i])
                break;
            ret = vp[i];
        }
        return ret;
    }
};
