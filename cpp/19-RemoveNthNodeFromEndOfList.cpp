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