// 1
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(root==NULL||p==NULL||q==NULL)
    return NULL;
    else if((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val<root->val))
    return root;
    else if((p->val<root->val&&q->val==root->val)||(p->val==root->val&&q->val>root->val)||(p->val==root->val&&q->val<root->val)||(p->val>root->val&&q->val==root->val))
    return root;
    else if(p->val<root->val&&q->val<root->val)
    lowestCommonAncestor(root->left,p,q);
    else if(p->val>root->val&&q->val>root->val)
    lowestCommonAncestor(root->right,p,q);
}


// 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return NULL;
        if (p->val>q->val) return lowestCommonAncestor(root,q,p);

        if(p->val>root->val&&root->right) return lowestCommonAncestor(root->right,p,q);
        if(q->val<root->val&&root->left) return lowestCommonAncestor(root->left,p,q);
        //if(p->val<=root->val&&root->val<=q->val) 
            return root;

    }
};
