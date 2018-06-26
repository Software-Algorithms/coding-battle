//
// https://www.lintcode.com/problem/convert-binary-tree-to-linked-lists-by-depth/description
//

/*
 * BFS, Binary Tree
 *
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        if(!root) return vector<ListNode*>();
        
        vector<ListNode*> res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            ListNode* levelHead = new ListNode(-1);
            ListNode* p = levelHead;
            for(int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                p->next = new ListNode(t->val);
                p = p->next;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(levelHead->next);
        }
        
        return res;
    }
};

//
//




