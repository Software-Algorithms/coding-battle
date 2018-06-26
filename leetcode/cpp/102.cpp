/*
 * BFS, Binary Tree
 *
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            int len = queue.size();
            vector<int> level;
            for(int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        
        return res;         
    }
};

// Conclusion:
// Typical.




