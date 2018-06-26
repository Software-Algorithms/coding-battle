/*
 * Binary Tree, Recursion
 *
 *
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root->left) inorder(root->left, res);
        res.push_back(root->val);
        if (root->right) inorder(root->right, res);
    }
};


/*
 * Binary Tree, Iteration
 *
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};

