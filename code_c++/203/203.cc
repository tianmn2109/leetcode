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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode *tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode *prev = tempHead;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *temp = cur;
            cur = cur->next;
            if (temp->val == val) {
                prev->next = cur;
                delete temp;
            }
            else {
                prev = temp;
            }
        }
        head = tempHead->next;
        delete tempHead;
        return head;
    }
};
