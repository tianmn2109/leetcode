// 1
I think my code is easy to understand and short enough, so I want to share it:

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > levelval;
        recrvzigzagLevelOrder(root, levelval, 0);
        return levelval;
    }

    void recrvzigzagLevelOrder(TreeNode* root, vector<vector<int> >& levelval, int level) {
        if( root == nullptr ) return ;
        if( levelval.size() < level+1 )
            levelval.push_back(vector<int>());
        if(level%2 == 0)
            levelval[level++].push_back(root->val);
        else{
            levelval[level].insert(levelval[level].begin(),root->val);
            ++level;
        }
        recrvzigzagLevelOrder(root->left, levelval, level);
        recrvzigzagLevelOrder(root->right, levelval, level);
        return ;
    }




