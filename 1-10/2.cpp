/* 算法思想
 * 1: 如果有一个链表为空，则返回另一个链表。
 * 2: 当两个链表都不为空的时候，从头开始，相对应的节点相加，并且还应该加上低位
 *    的进位(carray).
 * 3: 当有一个链表加完，只需要加进位值好对外一个节点的值
 * 4: 最后加完后还有进位，则应该申请新的节点保存
 */

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
