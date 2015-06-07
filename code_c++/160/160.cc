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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int k1 = 0;
        int k2 = 0;
        ListNode *p = headA;
        while (p != NULL) {
            k1 ++;
            p = p->next;
        }
        ListNode *q = headB;
        while (q != NULL) {
            k2 ++;
            q = q->next;
        }
        int dis = abs(k1 - k2);
        if (k1 > k2) {
            p = headA;
            q = headB;
        }
        else {
            p = headB;
            q = headA;
        }
        while (dis --)
            p = p->next;
        while (p != NULL && q != NULL) {
            if (p == q)
                return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
