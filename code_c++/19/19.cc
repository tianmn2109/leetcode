/*
 * 两个指针 第一个比第二个先走k步
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * p, *q;
        p = q = head;
        int k = n;
        if (head == NULL)
            return NULL;
            
        if (head->next == NULL)
            return NULL;
        
        while (k-- && p != NULL) {
            p = p->next;
        }
        
        if (p == NULL) {
            ListNode * r = head;
            head = head->next;
            free(r);
            return head;
        }
        
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        ListNode * r = q->next;
        q->next = q->next->next;
        free(r);
        return head;
    }
};