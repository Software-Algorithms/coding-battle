/*
 * Linked List
 * 
 * Solution 1:
 *
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        } else {
            for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : NULL;
    }
    
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
};

/*
 * Linked List
 * 
 * Solution 2-1:
 *
 * 用环的思想来做，我们让两条链表分别从各自的开头开始往后遍历，当其中一条遍历到末尾时，
 * 我们跳到另一个条链表的开头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况是
 * 在交点处相遇，另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指
 * 针走过的路程相同，是两个链表的长度之和，所以一定会相等。
 *
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



/*
 * Linked List
 * 
 * Solution 2-2:
 *
 * Same idea but conciser.
 *
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};