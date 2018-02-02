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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        ListNode* p = head;
        while(p && i < k) {
            p = p->next;
            i++;
        }
        if(i < k) return head;
        
        ListNode* cur = head->next;
        head->next = reverseKGroup(p, k);
        while(--i) {
            p = cur->next; // as temp
            cur->next = head;
            head = cur;
            cur = p;
        }
        
        return head;
    }
};