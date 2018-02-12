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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(!st.empty() || p) {
            if(p) {
                st.push(p);
                res.insert(res.begin(), p->val);  // Reverse the process of preorder
                p = p->right;             // Reverse the process of preorder
            } else {
                TreeNode* node = st.top(); st.pop();
                p = node->left;           // Reverse the process of preorder
            }
        }
        return res;        
    }
};