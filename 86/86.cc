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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallHead = NULL;
        ListNode *largeHead = NULL;
        ListNode *smallTail = NULL;
        ListNode *largeTail = NULL;
        ListNode *p = head;
        while (p != NULL) {
            ListNode *r = p;
            p = p->next;
            if (r->val < x) {
                if (smallHead == NULL) {
                    smallHead = smallTail = r;
                }
                else {
                    smallTail->next = r;
                    smallTail = smallTail->next;
                }
                smallTail->next = NULL;
            }
            else {
                if (largeHead == NULL) {
                    largeHead = largeTail = r;
                }
                else {
                    largeTail->next = r;
                    largeTail = largeTail->next;
                }
                largeTail->next = NULL;
            }
        }
        if (smallHead == NULL)
            return largeHead;
        smallTail->next = largeHead;
        return smallHead;
    }
};
