// 1 class Solution {
public:
    ListNode *swapPairs(ListNode *head) 
    {
        if(!head) return NULL;

        if(head->next)
        {
            ListNode *temp = head, *nextHead = head->next->next;
            head = head->next;
            head->next = temp;
            head->next->next = swapPairs(nextHead);
        }
        return head;
    }
};

// 2 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {

        ListNode *p,*q,*pre;
        p=pre=head;
        while( p && p->next ) {

            if ( pre == head )
                head = pre->next;
            q = p->next;
            pre->next = p->next;
            p->next = p->next->next;
            q->next = p;
            pre = p;
            p = p->next;

        }
        return head;
    }
}
