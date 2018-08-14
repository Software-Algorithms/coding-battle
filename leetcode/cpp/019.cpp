/*
 * Two Pointers (Left and Right Pointers)
 *
 */

// version 1:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); //store for using afterward
        dummy->next = head;
        ListNode* pre = dummy;
        
        // find the length of the list
        int len = 0;
        while(pre->next) {
            pre = pre->next;
            len++;
        }
        
        // move step by step to the removing postion
        pre = dummy;
        while(len-- > n) {
            pre = pre->next;
        }
        pre->next = pre->next->next;
        
        return dummy->next;
    }
};

// version 2:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head;
        while(right && n--) {
            right = right->next;
        }
        if(!right) return head->next;
        while(right->next) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head;
    }
};

/*****
Conclusion:
1. dummy node
2. left --> right
*****/




