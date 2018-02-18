/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;
    
    void find_left(TreeNode *root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = st.top();
        st.pop();
        if(top->right) {
            find_left(top->right);
        }
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */