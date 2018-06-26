/*
 * Linked List
 *
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;

        ListNode* pre = prehead;
        ListNode* cur = head;
        while(cur != NULL) {
            if(cur->val == val) {
                pre->next = cur->next;
            }
            else {
                pre = pre->next;
            }
            cur = cur->next;
        }

        return prehead->next;
    }
};
