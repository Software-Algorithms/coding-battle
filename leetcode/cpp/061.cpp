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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        ListNode *tic = head, *tail = head;
        
        int size = 1;
        while(tail->next) {
            tail = tail->next;
            size++;
        }
        k = k%size;
        
        int nsteps = size - k;
        while(--nsteps) {
            tic = tic->next;
        }
        
        tail->next = head;
        head = tic->next;
        tic->next = NULL;
        
        return head;
    }
};