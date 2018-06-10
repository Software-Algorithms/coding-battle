/*****
 * Binary Tree, Recursion
 *
 */


/*****
 * Binary Tree, Iteration
 *
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        
        if(root) s.push(root);
        while(!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            res.push_back(p->val);
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
        
        return res;
    }
};

