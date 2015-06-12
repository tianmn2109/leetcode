//  1   iterative
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}

// 2  iterative
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        if (l1) extra += l1->val, l1 = l1->next;
        if (l2) extra += l2->val, l2 = l2->next;
        p->next = new ListNode(extra % 10);
        extra /= 10;
        p = p->next;
    }
    return preHead.next;
}



// 3   recursive

ListNode* addList(ListNode* l1, ListNode* l2, int carry) {
    if(!l1 && !l2) {
        if(carry) return new ListNode(carry);
        else return NULL;
    }
    int val = carry + (l1?l1->val:0) + (l2?l2->val:0);
    ListNode* newNode = new ListNode(val%10);
    newNode->next = addList(l1?l1->next:NULL, l2?l2->next:NULL, val/10);
    return newNode;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addList(l1, l2, 0);
}

