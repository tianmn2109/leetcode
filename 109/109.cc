/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *subTree(vector<int> &v, int start, int end) {
        if (start > end)
            return NULL;
        int middle = (start + end) / 2;
        TreeNode *temp = new TreeNode(v[middle]);
        temp->left = subTree(v, start, middle - 1);
        temp->right = subTree(v, middle + 1, end);
    }
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        return subTree(v, 0, v.size() - 1);
    }
};
