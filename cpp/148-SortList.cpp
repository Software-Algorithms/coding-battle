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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < len; step <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while(cur) {
                left = cur;
                right = splitList(left, step);
                cur = splitList(right, step);
                tail = mergeLists(left, right, tail);
            }
        }
        return dummy.next;
    }
    
    ListNode* splitList(ListNode* head, int n) {
        for(int i = 1; head && i < n; i++) {
            head = head->next;
        }
        if(head == NULL) return NULL;
        ListNode* second = head->next;
        head->next = NULL;
        return second;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        while(cur->next) cur = cur->next;
        return cur;
    }
};