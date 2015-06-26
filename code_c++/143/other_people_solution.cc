This problem could be solved by recursion, we first dig down to the middle node of the list, and recurse back from that point, the time complexity is O(N), and faster than existing algorithm. 1 -> 2 ->3 ->4, first dig down to 3, then recurse back, concatenate 2->3 (which already together), then 1->4(we return next node of each node starting from middle one)

public void reorderList(ListNode head){
          if(head == null || head.next == null) return;
          ListNode h = reorderList(head, head,head);
     }

public ListNode reorderList(ListNode prev, ListNode slow, ListNode faster){
    if(faster == null || faster.next == null) {
        if(faster != null) {
            ListNode reverse = slow.next;
            slow.next = null;
            return reverse;
        }
        prev.next = null;
        return slow;
    }
    ListNode retNode = reorderList(slow, slow.next, faster.next.next);
    // concanate
    ListNode temp = retNode.next;
    retNode.next = slow.next;
    slow.next = retNode;
    return temp;
}
