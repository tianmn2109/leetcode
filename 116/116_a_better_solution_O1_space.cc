/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return ;
        TreeLinkNode *curLevel = root;
        while (root->left != NULL) {
            curLevel = root;
            while (curLevel != NULL) {
                if (curLevel->left != NULL)
                    curLevel->left->next = curLevel->right;
                if (curLevel->right != NULL && curLevel->next != NULL)
                    curLevel->right->next = curLevel->next->left;
                curLevel = curLevel->next;
            }
            root = root->left;
        }
    }
};