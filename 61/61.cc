/*
 * the right value may larger than the real len, so it should cauculate the mod of the right value firstly.
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

    ListNode *rotateRight(ListNode *head, int k) {

        if (k == 0 || head == NULL)
            return head;

        ListNode *p = head;
        ListNode *q = head;
        int num = 0;
        ListNode * cur = head;
        while (cur) {
            cur = cur->next;
            num ++;
        }
        k = k % num;

        if (k == 0)
            return head;
        while (k --) {
            q = q->next;
        }
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        
        ListNode * rotate = p->next;
        p->next = NULL;
        q->next = head;
        return rotate;
    }
};
