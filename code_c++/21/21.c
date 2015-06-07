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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *r = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                r = l1;
                l1 = l1->next;
            }
            else {
                r = l2;
                l2 = l2->next;
            }
            if (head == NULL) {
                head = tail = r;
            }
            else {
                tail->next = r;
                tail = tail->next;
            }
        }
        if (l1 == NULL)
            tail->next = l2;
        else
            tail->next = l1;
        return head;
    }
};
