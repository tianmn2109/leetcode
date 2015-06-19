// 1
There is no trick for this problem. Some people used slow/fast pointers to find the tail node but I don't see the benefit (in the sense that it doesn't reduce the pointer move op) to do so. So I just used one loop to find the length first.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};



