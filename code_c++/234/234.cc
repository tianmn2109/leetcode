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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
        return true;
        ListNode *first = head;
        ListNode *second = head;
        while (second->next != NULL && second->next->next != NULL) {
            first = first->next;
            second = second->next->next;
        }
        second = first->next;
        first->next = NULL;
        ListNode *tempHead = new ListNode(0);
        
        while (second != NULL) {
            ListNode *r = second;
            second = second->next;
            r->next = tempHead->next;
            tempHead->next = r;
        }
        second = tempHead->next;
        first = head;
        while (second != NULL) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
