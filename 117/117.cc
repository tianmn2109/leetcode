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
        TreeLinkNode *prev = NULL;
        TreeLinkNode *cur = root;
        TreeLinkNode *head = NULL;
        while (cur != NULL) {
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (head == NULL)
                        head = cur->left;
                    else
                        prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right != NULL) {
                    if (head == NULL)
                        head = cur->right;
                    else
                        prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            prev = NULL;
            head = NULL;
        }
    }
};
