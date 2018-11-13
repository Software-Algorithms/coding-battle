/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Linked List
 *
 * Idea:
 *
 * Complexity:
 *    Time: O(?)
 *
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
