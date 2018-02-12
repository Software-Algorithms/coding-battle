/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;  
        
        queue<TreeNode*> q;
        int level = 0;  
        q.push(root);  
        while(!q.empty()) {
            level++;
            int num = q.size();
            for(int i = 0; i < num; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) return level;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }  
        return 0;        
    }
};