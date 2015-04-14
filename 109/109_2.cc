#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode *subTree(ListNode *&node, int start, int end) {
       if (start > end)
            return NULL;
       int middle = (start + end) / 2;
       TreeNode *left = subTree(node, start, middle - 1);
       TreeNode *cur = new TreeNode(node->val);
       node = node->next;
       TreeNode *right = subTree(node, middle + 1, end);
       cur->left = left;
       cur->right = right;
       return cur;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        int len = 0;
        ListNode * p = head;
        while (p != NULL) {
            len ++;
            p = p->next;
        }
        return subTree(head, 0, len - 1);
    }
};
int main()
{
	ListNode *head = new ListNode(1);
	ListNode *temp = new ListNode(1);
	head->next = temp;
	Solution s;
	s.sortedListToBST(head);
	return 0;
}
