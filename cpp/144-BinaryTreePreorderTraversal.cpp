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
        stack<TreeNode*> st;
        
        if(!root) return res;
        
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            res.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        
        return res;        
    }
};
