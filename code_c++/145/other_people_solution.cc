Hi, this is a fundamental and yet classic problem. I share my three solutions here:

Iterative solution using stack --- O(n) time and O(n) space;
Recursive solution --- O(n) time and O(n) space (considering the costs of call stack);
Morris traversal --- O(n) time and O(1) space!!!
Iterative solution using stack:

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> toVisit;
    TreeNode* curNode = root;
    TreeNode* lastNode = NULL;
    while (curNode || !toVisit.empty()) {
        if (curNode) {
            toVisit.push(curNode);
            curNode = curNode -> left;
        }
        else {
            TreeNode* topNode = toVisit.top();
            if (topNode -> right && lastNode != topNode -> right)
                curNode = topNode -> right;
            else {
                nodes.push_back(topNode -> val);
                lastNode = topNode;
                toVisit.pop();
            }
        }
    }
    return nodes;
}
Recursive solution:

void postorder(TreeNode* root, vector<int>& nodes) {
    if (!root) return; 
    postorder(root -> left, nodes);
    postorder(root -> right, nodes);
    nodes.push_back(root -> val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    postorder(root, nodes);
    return nodes;
} 
Morris traversal:

void reverseNodes(TreeNode* start, TreeNode* end) {
    if (start == end) return;
    TreeNode* x = start;
    TreeNode* y = start -> right;
    TreeNode* z;
    while (x != end) {
        z = y -> right;
        y -> right = x;
        x = y;
        y = z;
    }
}
void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
    reverseNodes(start, end);
    TreeNode* node = end;
    while (true) {
        nodes.push_back(node -> val);
        if (node == start) break;
        node = node -> right;
    }
    reverseNodes(end, start);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> nodes;
    TreeNode* dump = new TreeNode(0);
    dump -> left = root;
    TreeNode* curNode = dump;
    while (curNode) {
        if (curNode -> left) {
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode)
                predecessor = predecessor -> right;
            if (!(predecessor -> right)) {
                predecessor -> right = curNode;
                curNode = curNode -> left;
            }
            else {
                reverseAddNodes(curNode -> left, predecessor, nodes);
                predecessor -> right = NULL;
                curNode = curNode -> right;
            }
        }
e curNode = curNode -> right;
    }
    return nodes;

