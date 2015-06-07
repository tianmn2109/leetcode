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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *tempHead = new ListNode(0);
        ListNode *p = head;
        while (p != NULL) {
            ListNode *r = p;
            p = p->next;
            r->next = tempHead->next;
            tempHead->next= r;
        }
        head = tempHead->next;
        delete tempHead;
        return head;
    }
};