#include <iostream>
#include <algorithm>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void merge(ListNode **head1, ListNode **head2) {
        if (*head1 == NULL) {
            *head1 = *head2;
            *head2 = NULL;
            return;
        }
        if (*head2 == NULL)
            return ;
        ListNode *p = *head1;
        ListNode *q = *head2;
        ListNode *tempHead = new ListNode(0);
        ListNode *r = tempHead;
        r->next = p;
        while (p != NULL && q != NULL) {
            if (q->val < p->val) {
                ListNode * temp = q->next;
                q->next = r->next;
                r->next = q;
                r = r->next;
                q = temp;
            }
            else {
                r = p;
                p = p->next;
            }
        }
        if (q != NULL)
            r->next = q;
        *head1 = tempHead->next;
        *head2 = NULL;
        free(tempHead);
    }

    ListNode *sortList(ListNode *head) {
       ListNode *carry = NULL;
       ListNode *counter[64] = {NULL};
       int fill = 0;
       if (head == NULL || head->next == NULL)
           return head;
       ListNode *p = head;
       while (p != NULL) {
           carry = p;
           p = p->next;
           carry->next = NULL;
           int i = 0;
           while (i < fill && counter[i] != NULL) {
               merge(&counter[i], &carry);
               swap(carry, counter[i ++]);
           }
           swap(carry, counter[i]);
           if (i == fill) fill ++;
       }
       for (int i = 1; i < fill; i ++)
           merge(&counter[i], &counter[i - 1]);
       head = counter[fill - 1];
       return head;
    }
};

int main()
{
	ListNode *head = new ListNode(2);
	ListNode * temp = new ListNode(1);
	head->next = temp;
	Solution s;
	head = s.sortList(head);

	while (head != NULL)
	{
		cout << head->val << " ";
		head= head->next;
	}
	cout << endl;

	return 0;
}
