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
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int num = q.size();
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
            for (int i = 1; i < num; i++) {
                TreeLinkNode *next = q.front();
                q.pop();
                cur->next = next;
                cur = next;
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            cur->next = NULL;
        }
    }
};
