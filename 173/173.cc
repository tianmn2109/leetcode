/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root) {
        pushStk(root);
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    /** @return the next smallest number */
    int next() {
        TreeNode *p = stk.top();
        stk.pop();
        pushStk(p->right);
        return p->val;
    }
    void pushStk(TreeNode *root) {
        if (root == NULL)
            return ;
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
