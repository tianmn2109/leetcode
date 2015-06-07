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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode *p = head;
        ListNode *q = head;

        while (q != NULL && q->next != NULL) {
            q = q->next->next;
            p = p->next;
            if (p == q)
                break;
        }
        if (q == NULL || q->next == NULL)
            return NULL;
        p = head;
        while (q != p) {
            q = q->next;
            p = p->next;
        }
        return p;
    }
};
