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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *r = new ListNode(head->val);
        r->next = head;
        ListNode * tempHead = r;
        while (q != NULL) {
            if (p->val == q->val) {
                while (q != NULL && p->val == q->val)
                    q = q->next;
                r->next = q;
                while (p != q) {
                    ListNode *s = p;
                    p = p->next;
                    free(s);
                }
                p = q;
                if (q!= NULL)
                    q = q->next;
            }
            else {
                q = q->next;
                p = p->next;
                r = r->next;
            }
        }
        head = tempHead->next;
        free(tempHead);
        return head;
    }
};
