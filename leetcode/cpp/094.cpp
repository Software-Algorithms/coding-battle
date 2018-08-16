/*
 * Binary Tree, Recursion
 *
 *
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        inorder(root, sol);
        return sol;
    }
    
    void inorder(TreeNode* root, vector<int>& sol) {
        if(!root) return;
        inorder(root->left, sol);
        sol.push_back(root->val);
        inorder(root->right, sol);
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

/*****
Idea:
1. 首先inorder的顺序是“左-根-右”，那么需要找到最左边的节点，再往上回溯，如果不用recursion的话，
那么久只能选择stack了；
2. 用p作为游历节点，从根节点或当前节点开始，逐个把左子节点压入stack中，到达最左节点后，需要考虑的
只有两种情况，（a）该节点是叶子节点，即没有左右子节点，（b）该节点存在右子节点；
3. 在处理这两种情况之前，一定是先把该节点的值推入结果res中，然后游历节点移到右子节点上，如果存在
右子节点，继续压入左子节点的操作，如果右子节点为空，则通过stack回溯到父节点或上一个左子节点。
*****/

