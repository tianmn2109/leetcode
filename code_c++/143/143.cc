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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ;
        ListNode *p = head;
        ListNode * q = head;
        while (q->next != NULL && q->next->next != NULL) {
            q = q->next->next;
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        ListNode * tempHead = new ListNode(0);
        while (q != NULL) {
            ListNode *r = q;
            q = q->next;
            r->next = tempHead->next;
            tempHead->next = r;
        }
        q = tempHead->next;
        free(tempHead);
        p = head;
        while (q != NULL)
        {
            ListNode *r = q;
            q = q->next;
            r->next = p->next;
            p->next = r;
            p = r->next;
        }
    }
};
