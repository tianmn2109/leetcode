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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *p = head;
        ListNode *q = head->next;
        while (q!= NULL) {
            if (q == p)
                return true;
            if (q->next != NULL && q->next->next != NULL)
                q = q->next->next;
            else 
                q = NULL;
            p = p->next;
        }
        return false;
    }
};
