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
       queue<TreeLinkNode *> q;
       int cur = 0;
       int last = 1;
       int next = 1;
       TreeLinkNode *prev = NULL;
       if (root != NULL)
          q.push(root);
       while(!q.empty()) {
           TreeLinkNode *temp = q.front();
           q.pop();
           temp->next = prev;
           prev = temp;
           cur ++;
           if (temp->right != NULL) {
               q.push(temp->right);
               next ++;
           }
           if (temp->left != NULL) {
               q.push(temp->left);
               next ++;
           }
           if (cur == last) {
               last = next;
               prev = NULL;
           }
       } 
    }
};