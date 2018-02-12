/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	// create copies
        RandomListNode *cur = head;
        while(cur) {
        	RandomListNode *copy = new RandomListNode(cur->label);
        	copy->next = cur->next;
        	cur->next = copy;
        	cur = copy->next;
        }

        // copy random pointers
        cur = head;
        while(cur) {
        	RandomListNode *copy = cur->next;
        	if(cur->random)
        		copy->random = cur->random->next;
        	cur = copy->next;
        }

        // decouple two link list
        cur = head;
        RandomListNode *newhead = (head == NULL) ? NULL : head->next;
        while(cur) {
        	RandomListNode *temp = cur->next;
        	cur->next = temp->next;
        	if(temp->next)
        		temp->next = temp->next->next;
        	cur = cur->next;
        }

        return newhead;        
    }
};