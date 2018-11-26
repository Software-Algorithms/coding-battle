/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        
        TreeLinkNode *head = NULL; // head node of each level
        TreeLinkNode *pre = NULL; // previous node
        TreeLinkNode *cur = root; // parent node

        while(cur) { // move downward
            while(cur) { // move rightward
                if(cur->left) {
                    if(pre) {
                        pre->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    pre = cur->left;
                }
                if(cur->right) {
                    if(pre) {
                        pre->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    pre = cur->right;
                }
                cur = cur->next; // move rightward
            }
            //move to next level
            cur = head;
            head = NULL;
            pre = NULL;
        }        
    }
};