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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size() > 1) {
            ListNode* l1 = lists[0];
            ListNode* l2 = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.insert(lists.begin(), mergeTwoLists(l1, l2));
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        return dummy->next;
    }
};