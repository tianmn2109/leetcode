#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *tempHead = new ListNode(0);
        ListNode *p = head;
        while (p != NULL) {
            ListNode *r = p->next;
            p->next = NULL;
            ListNode *q = tempHead->next;
            ListNode *s = tempHead;
            while (q != NULL) {
                if (p->val < q->val) {
                    p->next = s->next;
                    s->next = p;
                    break;
                }
                else {
                    s = q;
                    q = q->next;
                }
            }
            if (q == NULL)
                s->next = p;
            p = r;
        }
        head = tempHead->next;
	delete tempHead;
        return head;
    }
};

int main()
{
	ListNode * head = new ListNode(1);
	ListNode * temp = new ListNode(1);
	head->next = temp;
	Solution s;
	head = s.insertionSortList(head);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
