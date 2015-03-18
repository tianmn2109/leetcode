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

        ListNode * p = head;
        ListNode * q = head->next;
        while (q != NULL) {
            if (q->val == p->val) {
                ListNode * r = q;
                q = q->next;             // the p has to point to the new q when the duplicate happens
                p->next = q;
                free(r);
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};
