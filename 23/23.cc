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
    static bool cmp(const ListNode * n1, const ListNode * n2) {
        return n1->val > n2->val;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode *mergeHead = NULL;
        ListNode *mergeTail = NULL;
        vector<ListNode *> minHeap;
        for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); it ++)
            if (*it != NULL)
                minHeap.push_back(*it);
        make_heap(minHeap.begin(), minHeap.end(), cmp);
        while (minHeap.size() != 0) {
            pop_heap(minHeap.begin(), minHeap.end(), cmp);
            ListNode *cur = minHeap.back();
            minHeap.pop_back();
            if (cur->next != NULL) {
                minHeap.push_back(cur->next);
                push_heap(minHeap.begin(), minHeap.end(), cmp);
            }
            cur->next = NULL;
            if (mergeHead == NULL) {
                mergeHead = mergeTail = cur;
            }
            else {
                mergeTail->next = cur;
                mergeTail = cur;
            }
        }
        return mergeHead;
    }
};
