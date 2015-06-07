/*
 * reverse k nodes everytime. 
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 1)
            return head;
        
        ListNode * p = head;
        ListNode * q = head;
        ListNode * r = head;
        ListNode * t = NULL;
        
        while (p != NULL) {
            int s = k;
            while (--s && q != NULL)
                q = q->next;
            if (q == NULL)
                return head;
            if (t == NULL)
                head = q;
            else
                t->next = q;
                
            t = p;
            r = q->next;
            while (p != q) {
                ListNode * tmp = p;
                p = p->next;
                tmp->next = q->next;
                q->next = tmp;
            }

            p = q = r;
            
        }
        return head;
    }
};
