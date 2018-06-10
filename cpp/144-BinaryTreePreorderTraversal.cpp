/*****
 * Solution 1:
 * Binary Tree, Recursion
 *
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return res;
        res.push_back(root->val);
        if(root->left) preorderTraversal(root->left);
        if(root->right) preorderTraversal(root->right);
        return res;
    }
    
private:
    vector<int> res;
};


/*****
 * Solution 2:
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



/*****
 * Solution 3:
 * Binary Tree
 *
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->right;
            }
        }
        return res;
    }
};

