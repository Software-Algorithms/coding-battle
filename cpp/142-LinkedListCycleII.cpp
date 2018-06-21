/*
 * Two Pointers (Fast and slow pointers)
 *
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
    
        while(slow && fast) {
            slow = slow->next;
            if (fast->next == NULL) return NULL;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
    
        if(!isCycle) return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    
        return slow;
    }
};

// Conclusion:




