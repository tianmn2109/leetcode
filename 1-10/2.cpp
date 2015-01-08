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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode * head = NULL;
        ListNode * tail = NULL;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode * temp = new ListNode(sum);
            if (head == NULL) {
                head = tail = temp;
            }
            else {
                tail-> next  = temp;
                tail = temp;
            }
            l1 = l1->next;   // error: memory limit exceeded because of forgetting make the pointer point to the next node
            l2 = l2->next;   // error: memory limit exceeded because of forgetting make the pointer point to the next node
        }
        
        ListNode * l = (l1 == NULL) ? l2 : l1;
        while (l != NULL) {
            int sum = l->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode * temp = new ListNode(sum);
            tail->next = temp;
            tail = tail-> next;
            l = l->next;   // error: memory limit exceeded because of forgetting make the pointer point to the next node
        }
        
        if (carry > 0) {
            ListNode * temp = new ListNode(carry);
            tail-> next = temp;
            tail = temp;
        }
        
        return head;
    }
};
