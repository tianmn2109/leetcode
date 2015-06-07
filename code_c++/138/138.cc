/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *p1 = NULL;
        RandomListNode *p2 = NULL;
        RandomListNode *cloneHead = NULL;
        RandomListNode *tail = NULL;
        p1 = head;
        while (p1 != NULL) {
            p2 = new RandomListNode(p1->label);
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
        }
        p1 = head;
        while (p1 != NULL) {
            if (p1->random != NULL)
                p1->next->random = p1->random->next;
            p1 = p1->next->next;
        }
        p1 = head;
        p2 = NULL;
        while (p1 != NULL) {
            RandomListNode *r = p1->next->next;
            p2 = p1->next;
            if (cloneHead == NULL) {
                cloneHead = tail = p2;
                tail->next = NULL;
            }
            else {
                tail->next = p2;
                tail = p2;
                tail->next = NULL;
            }
            p1->next = r;
            p1 = r;
        }
        return cloneHead;
    }
};
