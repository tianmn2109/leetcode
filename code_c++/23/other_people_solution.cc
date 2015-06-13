// 1 simple good idea.
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// 2
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }

        if (q.empty()) {
            return NULL;
        }

        ListNode* result = q.top();
        q.pop();
        if (result->next) {
            q.push(result->next);
        }

        ListNode* tail = result;            
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }

        return result;
    }
};


// 3 similar to 1
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {

struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
struct ListNode *cur = head;
while(list1 && list2){
    if(list1->val > list2->val){
        cur->next = list2;
        list2 = list2->next;
    }else{
        cur->next = list1;
        list1 = list1->next;
    }
    cur = cur->next;
}

if(list1){
    cur->next = list1;
}else{
    cur->next = list2;
}

cur = head->next;
free(head);
return cur;

}

struct ListNode *merge(struct ListNode *lists[],int beg,int end){

if(beg > end)
    return NULL;
if(beg == end)
    return lists[beg];

int mid = (beg + end) / 2;
struct ListNode *left = merge(lists,beg,mid);
struct ListNode *right = merge(lists,mid+1,end);

return mergeTwoLists(left,right);

}

struct ListNode *mergeKLists(struct ListNode *lists[], int k) {

return merge(lists,0,k-1);

}
