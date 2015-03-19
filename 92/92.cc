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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL)
            return head;

        int k = n - m + 1;
        if (k <= 1)
            return head;

        ListNode * p = NULL;
        ListNode * q = NULL;
        ListNode * s = NULL;
        ListNode * tempHead = new ListNode(0);
        tempHead->next = head;

        p = tempHead;
        while (-- m) 
            p = p->next;

        q = s = p->next;
        while (k -- && q != NULL) {
            ListNode * r = q;
            q = q->next;
            r->next = p->next;
            p->next = r;
        }
        s->next = q;
        head = tempHead->next;
        delete tempHead;
        return head;
    }
};
