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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        ListNode *cur = head, *pre = dummy, *next = NULL;
        while(cur) {
            next = cur->next;
            while(pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
            
            pre = dummy;
        }
        return dummy->next;
    }
};