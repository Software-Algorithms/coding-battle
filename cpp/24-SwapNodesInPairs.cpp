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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        dummy->next = head;
        while (head && head->next) {
            ListNode *nxt = head->next->next;
            pre->next = head->next;
            head->next->next = head;
            head->next = nxt;
            pre = head;
            head = pre->next;
        }
        return dummy->next;        
    }
};