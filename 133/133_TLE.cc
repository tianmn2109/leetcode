/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return dfs(node);
    }
    UndirectedGraphNode * dfs(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        for (int i = 0; i < (node->neighbors).size(); i ++) {
            if (node != (node->neighbors)[i])
                (ret->neighbors).push_back(dfs((node->neighbors)[i]));
            else
                (ret->neighbors).push_back(ret);
        }
        return ret;
    }
};
