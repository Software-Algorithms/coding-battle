/*
 * Linked List, Math
 *
 */

// version 1:
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(0);
        ListNode* p =  head;
        int sum = 0;
        while(l1||l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(sum%10);
            p = p->next;
            sum = sum/10;
        }
        if(sum == 1) p->next = new ListNode(1);
        return head->next;  
    }
};

// version 2:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prehead = new ListNode(0);
        ListNode *p = prehead;
        int addon = 0, carry = 0;
        while(l1 || l2 || carry) {
            addon = carry;
            if(l1) { addon += l1->val; l1 = l1->next; }
            if(l2) { addon += l2->val; l2 = l2->next; }
            carry = addon / 10;
            addon = addon % 10;
            p->next = new ListNode(addon);
            p = p->next;
        }
        return prehead->next;
    }
};

