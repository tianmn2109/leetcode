struct ListNode* reverseList(struct ListNode* head) {
    if(NULL==head) return head;

    struct ListNode *p=head;
    p=head->next;
    head->next=NULL;
    while(NULL!=p){
        struct ListNode *ptmp=p->next;
        p->next=head;
        head=p;
        p=ptmp;
    }
    return head;
}
above is the iterative one. simple, nothing to explain.

struct ListNode* reverseListRe(struct ListNode* head) {
    if(NULL==head||NULL==head->next) return head;

    struct ListNode *p=head->next;
    head->next=NULL;
    struct ListNode *newhead=reverseListRe(p);
    p->next=head;

    return newhead;
}
above is the recursively one.Both are accepted.
