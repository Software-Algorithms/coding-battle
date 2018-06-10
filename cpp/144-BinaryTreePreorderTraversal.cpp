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
// Conclusion:
// 下面这种写法使用了一个辅助结点p，这种写法其实可以看作是一个模版，
// 对应的还有中序和后序的模版写法，形式很统一，方便于记忆。辅助结点
// p初始化为根结点，while循环的条件是栈不为空或者辅助结点p不为空，
// 在循环中首先判断如果辅助结点p存在，那么先将p加入栈中，然后将p的
// 结点值加入结果res中，此时p指向其左子结点。否则如果p不存在的话，
// 表明没有左子结点，我们取出栈顶结点，将p指向栈顶结点的右子结点.

