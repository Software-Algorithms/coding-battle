/*
 * Two Pointers (Fast and slow pointers)
 *
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while(q && q->next) {
            p = p->next;
            q = q->next->next;
            if(p == q) return true;
        }
        return false;
    }
};

// Conclusion:




