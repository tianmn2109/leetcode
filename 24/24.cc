/*
 * p ,q 两个指针分别指向要交换指针的前一个节点
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode * p = new ListNode(0);
        ListNode * tempHead = p;
        ListNode * q = p->next = head;
        q = head;
        while (p != NULL && q!= NULL && p->next != NULL && q->next != NULL) {
            ListNode * r = q->next;
            p->next = r;
            q->next = r->next;
            r->next = q;
            q = r;

            p = p->next->next;
            q= q->next->next;
        }
        return tempHead->next;
    }
};
