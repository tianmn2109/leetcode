/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * mergeTwoLists(ListNode *head1, ListNode *head2) {
        if (head1 == NULL)
            return head2;

        if (head2 == NULL)
            return head1;
        ListNode *p = head1;
        ListNode *q = head2;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *r = NULL;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                r = p;
                p = p->next;
            }
            else {
                r = q;
                q = q->next;
            }
            if (head == NULL)
                head = tail = r;
            else {
                tail->next = r;
                tail = tail->next;
            }
        }
        ListNode * temp = (p == NULL) ? q : p;
        tail->next = temp;
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        ListNode * head = lists[0];
        for (int i = 1; i < lists.size(); i ++)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }
};
