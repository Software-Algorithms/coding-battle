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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        if(!curA || !curB) return NULL; 
        
        while(curA != curB) {
            curA = curA->next;
            curB = curB->next;
            if(curA == curB) return curA; //this is necessary in case no intersection
            if(curA == NULL) curA = headB;
            if(curB == NULL) curB = headA;
        }
        
        return curA;        
    }
};