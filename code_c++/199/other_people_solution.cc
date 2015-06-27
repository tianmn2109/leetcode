// 1    
vector<int> rightSideView(TreeNode* root) {
        vector<int> right_side_view;
        if(!root) return right_side_view;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        int numLevelNodes = 1;
        while(!toVisit.empty()) {
            vector<int> level;
            for (int i = 0; i < numLevelNodes; i++) {
                TreeNode* node = toVisit.front();
                toVisit.pop();
                if(node -> left) toVisit.push(node -> left);
                if(node -> right) toVisit.push(node -> right);
                if(i==numLevelNodes-1)
                    right_side_view.push_back(node->val);
            }
            numLevelNodes = toVisit.size();
        }
        return right_side_view;
    }


// 2
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};


// 3
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode*>mQ;
        vector<int> ret;
        if(!root)return ret;
        mQ.push(root);
        while(!mQ.empty()){
            ret.push_back(mQ.back()->val);
            for(int i=mQ.size();i>0;i--){
                TreeNode *tn=mQ.front();
                mQ.pop();
                if(tn->left)mQ.push(tn->left);
                if(tn->right)mQ.push(tn->right);
            }
        }
        return ret;
    }
};

// 4
class Solution {
    private:
        vector<int> res;
        void rightSideView_(TreeNode *root, int level) {
            if (root) {
                if (res.size()<= level) 
                    res.push_back(root->val);
                rightSideView_(root->right, level+1);
                rightSideView_(root->left, level+1);
            }
        }

    public:
        vector<int> rightSideView(TreeNode *root) {
            res.clear();
            rightSideView_(root, 0);
            return res;
        }
    };
