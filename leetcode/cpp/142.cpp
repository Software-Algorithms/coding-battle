/*
 * Two Pointers (Slow and Fast Pointers)
 *
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
    
        while(slow && fast) {
            slow = slow->next;
            if (fast->next == NULL) return NULL;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
    
        if(!isCycle) return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    
        return slow;
    }
};

// version 2:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

/*****
Conclusion:

For better understanding why they meet in the entering point of the loop:

1. In the first step, slow pointer moves one step a time, and fast pointer moves two step a time, so when the
    meet, we have
        2x - x = n k
        x = n k
    where x is the steps taken by the slow pointer, n is an integer, k is the number of steps for a full circle
2. Now the current position of the two pointer is x, and its distance to the origin is also x = nk. This means
   if a pointer takes one step each time from origin, and another pointer takes one step each time from x, their
   distance will be x - 0 = nk, hence they will definitely meet.
3. Where will they meet? The answer is simple: they will meet as long as the first pointer enters the loop, then
   they overlap forever. Image we "roll" the path before the loop onto the loop, then the origin should be at 
   exactly the same location as the meet point, because x - 0 = nk. These two pointers are always located at the
   same angle and will see each other when both of them enter the loop.

There is also a good explanation in Youtube:
https://youtu.be/-YiQZi3mLq0
*****/
    
    
    
    
