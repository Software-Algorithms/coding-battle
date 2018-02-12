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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        
        queue.push(root);
        while(!queue.empty()) {
            int len = queue.size();
            vector<int> level;
            for(int i = 0; i < len; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            res.push_back(level);
        }
        
        return res;         
    }
};