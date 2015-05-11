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
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> ret;
        if (start > end) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = start; i <= end; i ++) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            for (int s = 0; s < left.size(); s ++)
                for (int k = 0; k  < right.size(); k ++) {
                    TreeNode *root = new TreeNode(i + 1);
                    root->left = left[s];
                    root->right = right[k];
                    ret.push_back(root);
                }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(0, n - 1);
    }
};